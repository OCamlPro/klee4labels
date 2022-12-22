(**************************************************************************)
(*                                                                        *)
(*    Copyright 2022 OCamlPro SAS                                         *)
(*                                                                        *)
(*  All rights reserved. This file is distributed under the terms of the  *)
(*  GNU General Public License version 3.0, as described in the LICENSE   *)
(*  file in the root directory of this source tree.                       *)
(*                                                                        *)
(**************************************************************************)

open Lwt.Syntax

exception NotADirectory of string

module Feedback = (val (Options.Feedback.build "Utils"))

let failwith fmt =
  Format.kasprintf failwith fmt

let forbidden_char = function
  | '&' | ' ' | '|' | ';'
  | '\x0C' | '\n' | '\r' | '\t' -> true
  | _ -> false

let check_file_name dir =
  String.iter
    (fun c -> if forbidden_char c then failwith "Invalid dir name %s" dir)
    dir

let create_dir dir =
  check_file_name dir;
  let rec create dir =
    let* exists = Lwt_unix.file_exists dir in
    if exists && Sys.is_directory dir
    then Lwt.return ()
    else begin
      let parent = Filename.dirname dir in
      let* () = create parent in
      Lwt_unix.mkdir dir 0o755
    end
  in
  create dir


let watchdir ~inot dir evts =
  (* Ensure we're watching a directory *)
  try Lwt_inotify.add_watch inot dir (S_Onlydir :: evts)
  with Unix.Unix_error _ -> Lwt.fail (NotADirectory dir)

let rec waitfor ?inot file =
  let open Inotify in
  let open Filename in
  let* ok = Lwt_unix.file_exists file in
  if ok && Sys.is_directory file
  then Lwt.return ()
  else begin
    let parent, filename = dirname file, basename file in
    let* inot = match inot with
      | Some inot -> Lwt.return inot
      | None -> Lwt_inotify.create ()
    in
    let* () = waitfor ~inot parent in
    let* wtch = watchdir ~inot parent [S_Create] in
    let rec wait () =
      let* evt = Lwt_inotify.read inot in
      match evt with
      | w, _, _, _ when w <> wtch ->
          wait ()
      | _, ek, _, Some f when f = filename && List.mem Isdir ek ->
          Lwt.return ()
      | _ ->
          wait ()
    in
    let* () = wait () in
    Lwt_inotify.rm_watch inot wtch
  end


let monitor_entry ~on_event entry =
  let open Inotify in
  let open Filename in
  let pp_event fmt e = Format.pp_print_string fmt (string_of_event e) in
  let* inot = Lwt_inotify.create () in
  (* Checks `dir` is indeed a directory. *)
  let* wtch = match entry with
    | `Dir d ->
        (* Wait for watched directory to exist, in case. *)
        let* () = waitfor ~inot d in
        watchdir ~inot d [S_Close_write]
    | `File f ->
        (* Wait for directory including f to exist, in case. *)
        let* () = waitfor ~inot (dirname f) in
        Lwt_inotify.add_watch inot f [S_Close_write]
  in
  (* Synchronization variable used to wait for `inot`'s underlying queue to be
     empty before calling `Lwt_inotify.close inot` and terminating
     `stop_watch`. *)
  let stopped: unit Lwt_mvar.t = Lwt_mvar.create_empty () in
  let rec watch () =
    let* evt = Lwt_inotify.read inot in
    match evt, entry with
    | (w, _, _, _), _ when w <> wtch ->
        watch ()
    | (_, ek, _, Some f), `Dir d when List.mem Close_write ek ->
        let* () = on_event @@ concat d f in
        watch ()
    | (_, ek, _, _), `File f when List.mem Close_write ek ->
        let* () = on_event f in
        watch ()
    | (_, ek, _, _), _ when List.mem Ignored ek ->
        Lwt_mvar.put stopped ()
    | _ ->
        Format.eprintf "Unexpected inotify event: %a@." pp_event evt;
        watch ()
  and stop_watch () =
    let* () = Lwt_inotify.rm_watch inot wtch in
    let* () = Lwt_mvar.take stopped in         (* wait for `inot` to be empty *)
    Lwt_inotify.close inot
  in
  Lwt.async watch;
  Lwt.return stop_watch

let monitor_dir ~on_close dir =
  monitor_entry ~on_event:on_close (`Dir dir)

let print_flags fmt = List.iter (Format.fprintf fmt "-D%s ")
let print_lib_paths fmt = List.iter (Format.fprintf fmt "-I %s ")
let print_list ~sep pp_elt fmt =
  Format.pp_print_list ~pp_sep:(fun fmt _ -> Format.fprintf fmt  "%s" sep) pp_elt fmt
let print_str_list ~sep fmt =
  print_list ~sep (fun fmt -> Format.fprintf fmt "%s") fmt


let empty_dir d =
  let files = Sys.readdir d in
  Array.iter begin fun f ->
    let f = Filename.concat d f in
    Feedback.debug "Unlink %s@." f;
    if Sys.is_directory f
    then ()
    else Unix.unlink f
  end files

let remove_dir d =
  empty_dir d;
  Unix.rmdir d

let file_exists f =
  let dir = Filename.dirname f in
  Array.exists
    (String.equal (Filename.concat dir f))
    (Sys.readdir dir)

let (|?|) f1 f2 x =
  match f1 x with
  | None -> f2 x
  | some -> some

let write_in filename f =
  let chan = open_out filename in
  f (Format.formatter_of_out_channel chan);
  close_out chan

let range =
  let rec _range acc i j =
    if i = j then j :: acc else _range (j :: acc) i (j - 1)
  in fun i j ->
  assert (i <= j);
  _range [] i j

let dirname_from_filename fname =
  let regexp = Str.regexp Filename.dir_sep in
  Str.global_replace regexp "_" fname

let sys_readdir dir =
  Sys.readdir dir |>
  Array.map (Filename.concat dir)
