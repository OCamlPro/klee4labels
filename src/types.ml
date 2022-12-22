(**************************************************************************)
(*                                                                        *)
(*    Copyright 2022 OCamlPro SAS                                         *)
(*                                                                        *)
(*  All rights reserved. This file is distributed under the terms of the  *)
(*  GNU General Public License version 3.0, as described in the LICENSE   *)
(*  file in the root directory of this source tree.                       *)
(*                                                                        *)
(**************************************************************************)

open Options

module Flag = struct
  type t =
    | Ignore
    | Naive
    | Optimized
  [@@deriving json_encoding]

  let to_string = function
    | Ignore -> "IGNORE"
    | Naive -> "NAIVE"
    | Optimized -> "OPTIMIZED"

  let compare t t' = match t, t' with
    | Ignore, Ignore
    | Naive, Naive
    | Optimized, Optimized -> 0
    | Ignore, (Naive | Optimized)
    | Naive, Optimized -> 1
    | Optimized, (Naive | Ignore)
    | Naive, Ignore -> -1
end

module Globals = struct

  let global_results_dir = "_results"
  let replayer_exe = "replayer.exe"
  let json_results = "results.json"
  let graph_results = "graph.py"

  module type S = sig
    val file : string
    val results_dir : string
    val replayer_exe : string

    module Feedback : Feedback.S
  end

  let build file : (module S) =
    let dname = Utils.dirname_from_filename file in
    let module G : S = struct
      let file = file
      let results_dir = Filename.concat global_results_dir dname
      let replayer_exe = Filename.concat results_dir replayer_exe

      module Feedback = (val (Feedback.build file))
    end
    in (module G : S)
end

module GlobalsAndFlag = struct
  module type S = sig
    include Globals.S
    val flag : Flag.t
  end

  let build (module G : Globals.S) flag =
    let module G = struct
      let file = G.file
      let dirname_from_flags = Flag.to_string flag
      let results_dir = Filename.concat G.results_dir dirname_from_flags
      let replayer_exe =
        Filename.concat
          results_dir
          Globals.replayer_exe

      let flag = flag

      module Feedback = (val (
          Options.Feedback.build dirname_from_flags
        ))
    end
    in (module G : S)
end


module TestKind = struct
  type t =
    | Ktest
    | Assert
    | Early
    | Other of string
  [@@deriving json_encoding]


  let get_file_kind file dir =
    (* assert (Filename.extension file) = ".ktest" *)
    let file_less_ext = Filename.chop_extension @@ Filename.basename file in
    let rec loop = function
      | [] -> Ktest
      | f :: tl ->
        if Filename.extension f = "" || String.length f < String.length file_less_ext
        then loop tl
        else
          let f_less_ext = String.sub f 0 (String.length file_less_ext) in
          if file_less_ext <> f_less_ext then loop tl
          else
            match Filename.extension f with
            | ".err" -> begin
                try
                  let extra_ext =
                    Filename.extension
                      (Filename.chop_extension f)
                  in
                  if extra_ext = ".assert"
                  then Assert
                  else Other (extra_ext ^ ".err")
                with Invalid_argument _ -> Other ".err"
              end
            | ".early" -> Early
            | ".ktest" | ".kquery" -> loop tl
            | ext -> Other ext
    in
    loop dir

  let test_is_assert_err f =
    Filename.extension f = ".err" &&
    Filename.extension (Filename.chop_extension f) = ".assert"

  let is_assert_err f =
    if Filename.extension f = ".err" &&
       Filename.extension (Filename.chop_extension f) = ".assert"
    then Some (Filename.chop_extension @@ Filename.chop_extension f)
    else None

  let is_early_err f =
    if Filename.extension f = ".early"
    then Some (Filename.chop_extension f)
    else None

  let is_ktest f =
    if Filename.extension f = ".ktest"
    then Some (Filename.chop_extension f)
    else None

  let is_ktest_only_and_not_optim flag dir f =
    match flag with
    | Flag.Optimized -> None
    | _ ->
      match is_ktest f with
      | None -> None
      | some ->
        match get_file_kind f (Array.to_list (Sys.readdir dir)) with
        | Ktest -> some
        | _ -> None
end

module Results = struct
  type t = {
    (* labels_covered: int list; *)
    labels_covered: (int * float) list;
    tests_generated: (string * TestKind.t) list;
    total_time: float;
    klee_time: float;
    options: (module GlobalsAndFlag.S);
    start_time: float;
    klee_start_time: float;
  }

  let get_flag t =
    let module M = (val t.options) in
    M.flag

  let enc = let open Json_encoding in
    conv
      (fun {
         labels_covered; tests_generated; total_time; klee_time;
         options = (module G); start_time; klee_start_time
       } -> (labels_covered, tests_generated, total_time,
             klee_time, (G.file, G.flag), start_time,
             klee_start_time))
      (fun (labels_covered, tests_generated, total_time, klee_time,
            (file, flag), start_time,
            klee_start_time) ->
        let options : (module GlobalsAndFlag.S) =
          GlobalsAndFlag.build (Globals.build file) flag
        in
        {
          labels_covered; tests_generated; total_time; klee_time;
          options; start_time; klee_start_time
        }
      )
      (obj7
         (req "labels_covered" (list @@ tup2 int float))
         (req "tests_generated" (list @@ tup2 string TestKind.enc))
         (req "total_time" float)
         (req "klee_time" float)
         (req "options" (tup2 string Flag.enc))
         (req "start_time" float)
         (req "klee_start_time" float)
      )

end
