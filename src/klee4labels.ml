(**************************************************************************)
(*                                                                        *)
(*    Copyright 2022 OCamlPro SAS                                         *)
(*                                                                        *)
(*  All rights reserved. This file is distributed under the terms of the  *)
(*  GNU General Public License version 3.0, as described in the LICENSE   *)
(*  file in the root directory of this source tree.                       *)
(*                                                                        *)
(**************************************************************************)

open Klee4labels_lib
open Lwt.Syntax
open Cmd_helpers.Syntax
open Options
open Types

let flags = Flag.[Ignore; Naive; Optimized]

let compile_replayer (module G : Globals.S) file =
  let cmd =
    Cmd_helpers.compile_replayer_cmd ["macros"] file G.replayer_exe
  in
  let>! _res = cmd in
  Lwt.return ()

let compile_llvm (module G : Globals.S) file flags : string Lwt.t =
  let output_name =
    let basename =
      let bfname = Filename.basename file in
      Format.sprintf "%s.bc" (Filename.chop_extension bfname)
    in
    Filename.concat G.results_dir basename
  in
  let>! _res = Cmd_helpers.compile_llvm_cmd flags ["macros"] file output_name in
  Lwt.return output_name

let replay (module G : Globals.S) testname =
  let cmd = Cmd_helpers.replay_cmd testname G.replayer_exe in
  let>! _res = cmd in
  Lwt.return ()

let should_i_replay (module G : GlobalsAndFlag.S) dir f =
  match Utils.(
      TestKind.is_assert_err
      (* |?| is_early_err *)
      |?| TestKind.is_ktest_only_and_not_optim G.flag dir
    ) f with
  | Some rawname -> Some (Format.sprintf "%s.ktest" rawname)
  | None -> None

let monitor_klee_dir (module G : GlobalsAndFlag.S) dir =
  let on_close f =
    match should_i_replay (module G) dir f with
    | Some testname -> begin
        let () =
          G.Feedback.debug
            "Test %s reached a new label, replaying@."
            testname
        in
        let* () =
          Lwt.catch
            begin fun () ->
              replay (module G : Globals.S) testname
            end
            begin function
              | Failure str ->
                G.Feedback.print
                  "Error while replaying test %s (%s): \
                   continue klee's analysis@." testname str;
                Lwt.return ()
              | exn -> raise exn
            end in
        let () =
          G.Feedback.debug
            "Replay of test %s over.@."
            testname
        in
        Lwt.return ()
      end
    | None -> Lwt.return () in
  let* _stop_monitoring = Utils.monitor_dir ~on_close dir in
  Lwt.return ()

(* let monitor_label_dir (module G : Globals) dir =
 *   Format.printf "Monitoring dir %s@." dir;
 *   let start = Unix.gettimeofday () in
 *   let (lwt, resolv) = Lwt.wait () in
 *   let res = ref [] in
 *   let lck = Lwt_mutex.create () in
 *   let on_close f =
 *     let now = Unix.gettimeofday () in
 *     match is_lbl f with
 *     | None -> G.Feedback.debug"Ignoring file %s@." f; Lwt.return ()
 *     | Some label ->
 *       G.Feedback.debug "New label %i found at time %f@." label now;
 *       let* () = Lwt_mutex.with_lock lck (fun () -> res := (label, now -. start) :: !res; Lwt.return ()) in
 *       Lwt.return ()
 *   in
 *   let* stop_monitoring = Utils.monitor_dir ~on_close dir in
 *
 *   let end_monitoring () =
 *     let* () = stop_monitoring () in
 *     Lwt.wakeup_later resolv !res;
 *     Lwt.return ()
 *   in
 *   Lwt.return (end_monitoring, lwt) *)

let start_klee (module G : GlobalsAndFlag.S) llvm_file =
  let klee_cmd = Cmd_helpers.start_klee_cmd llvm_file in
  let () =
    try Utils.remove_dir klee_cmd.output_dir
    with
    | Unix.(Unix_error (ENOENT, _, _))
    | Sys_error _ -> () in
  let _stop_monitoring = monitor_klee_dir (module G) klee_cmd.output_dir in
  G.Feedback.print "Starting klee's execution@.";
  let>! res = klee_cmd.cmd in
  G.Feedback.print "Klee ended@.";
  Lwt.return (klee_cmd, res)


let test_files dir =
  let files = Array.to_list @@ Sys.readdir dir in
  List.filter_map
    (fun f ->
       if Filename.extension f = ".ktest"
       then Some (Filename.concat dir f, TestKind.get_file_kind f files)
       else None
    ) files


let _replay_all_tests (module G : Globals.S) klee_output_dir =
  let tests = test_files klee_output_dir in
  Lwt_list.iter_s
    (fun (file, _) ->
       Lwt.catch (fun () ->
           replay
             (module G : Globals.S)
             file
         ) (function
           | Failure str ->
             Format.eprintf "Replaying failed: %s. Ignoring.@." str;
             Lwt.return ()
           | exn -> raise exn
         )
    )
    tests

let post_process (module G : GlobalsAndFlag.S) _klee_output_dir = Lwt.return ()
  (* if List.exists (fun fl -> fl = "NAIVE" || fl = "INGORE") G.flags
   * then replay_all_tests (module G) klee_output_dir *)
  (* else Lwt.return () *)

let get_results (module G : GlobalsAndFlag.S) =
  let files = Array.to_list @@ Sys.readdir G.results_dir in
  let labels =
    List.filter_map begin fun f ->
      if not(
          Sys.is_directory (Filename.concat G.results_dir f)
        )
      && Filename.extension f = ".lbl"
      then Some (Filename.chop_extension f)
      else None
    end
      files
  in
  List.fast_sort String.compare labels

let labelfile (module G : Globals.S) (id : int) =
  id |> Format.sprintf "%i.lbl" |> Filename.concat G.results_dir

let label_covered_with_time
    (module GF : GlobalsAndFlag.S)
    klee_start_time
    ids =
  List.map (fun lbl ->
      let time =
        let stats =
          let fname = labelfile (module GF) lbl in
          Unix.stat fname
        in
        stats.st_mtime -. klee_start_time
      in lbl, time
    ) ids

let run_with_flags (module G : GlobalsAndFlag.S) file =
  let start_time = Unix.gettimeofday () in
  let* () = Utils.create_dir G.results_dir in
  let () = Utils.empty_dir (Filename.dirname G.replayer_exe) in
  let* () = compile_replayer (module G) file in
  let* bc_file = compile_llvm (module G) file G.flag in
  (* let* (end_monitor, result) = monitor_label_dir (module G : Globals) G.results_dir in *)
  (* let* labels_covered = monitor_label_dir (module G : Globals) G.results_dir in *)
  let klee_start_time = Unix.gettimeofday () in
  let* klee_cmd, klee_stats = start_klee (module G) bc_file in

  let* () = post_process (module G) klee_cmd.output_dir in
  (* let* () = end_monitor () in *)
  (* let* labels_covered = result in *)
  (* let* () = end_monitoring_labels () in *)
  (* let labels_covered = !labels_covered in *)
  let labels_covered = get_results (module G) |> List.map int_of_string in

  let tests_generated = test_files klee_cmd.output_dir in

  let total_time = Unix.gettimeofday () -. start_time in

  let labels_covered =
    label_covered_with_time (module G) klee_start_time labels_covered in

  Lwt.return Results.{
    labels_covered;
    tests_generated;
    total_time;
    klee_time = klee_stats.exec_time;
    options = (module G);
    start_time;
    klee_start_time;
  }

let print_test_details fmt tests =
  let ktest, assert_err, early, other, len =
    List.fold_left (fun (ktest, assert_err, early, other, len) (_, kind) -> match kind with
        | TestKind.Ktest -> (ktest + 1, assert_err, early, other, len + 1)
        | Assert -> (ktest, assert_err + 1, early, other, len + 1)
        | Early -> (ktest, assert_err, early + 1, other, len + 1)
        | Other _ -> (ktest, assert_err, early, other + 1, len + 1)
      ) (0, 0, 0, 0, 0) tests
  in
  Format.fprintf fmt "%i (%i tests, %i assertions, %i early errors, %i other)"
    len ktest assert_err early other

let print_results (module G : Globals.S) =
  List.iter
    (fun Results.{
       labels_covered;
       tests_generated;
       total_time;
       klee_time;
       options = (module GF : GlobalsAndFlag.S);
       start_time = _;
       klee_start_time = _;
     } ->

       G.Feedback.print "%s mode:@." (Types.Flag.to_string GF.flag);
       G.Feedback.print "Total time: %fms@." total_time;
       G.Feedback.print "Klee execution: %fms@." klee_time;
       G.Feedback.print "Number of labels covered: %i@."
         (List.length labels_covered);
       (* G.Feedback.print "Labels covered: %a@."
        *   (Utils.print_list ~sep:", ") labels_covered; *)
       G.Feedback.print "Labels covered: %a@."
         (Format.pp_print_list ~pp_sep:(fun fmt _ -> Format.fprintf fmt  ",") (fun fmt (lbl, time) -> Format.fprintf fmt "%i(%fs)" lbl time))
         (List.fast_sort (fun (_, ti) (_, tj) -> Float.compare ti tj) labels_covered);
       (* G.Feedback.print "Labels covered: %a@."
        *   (Format.pp_print_list ~pp_sep:(fun fmt _ -> Format.fprintf fmt  ",") (fun fmt (lbl, tm) -> Format.fprintf fmt "%i(%f)" lbl tm)) labels_covered; *)
       G.Feedback.print "Number of tests generated by klee: %a@."
         print_test_details tests_generated;
    )

let run file =
  let module G : Globals.S = (val Globals.build file) in
  let* () = Utils.create_dir G.results_dir in
  let* results =
    Lwt_list.map_s (fun flag ->
        G.Feedback.debug "Flag: %s@." (Types.Flag.to_string flag);
        let module GF =
          (val GlobalsAndFlag.build (module G) flag)
        in
        run_with_flags (module GF) file
      ) flags
  in
  let () = print_results (module G) results in
  let () =
    Plot.write_chart_in_file
      results
      (Filename.concat G.results_dir Globals.graph_results)
  in
  let () =
    Plot.write_json_results_in_file
      results
      (Filename.concat G.results_dir Globals.json_results)
  in
  Lwt.return ()

let () =
  let () =
    try Options.init ()
    with
    | Arg.Help msg
    | Arg.Bad msg -> Format.printf "%s" msg; exit 1
  in
  Lwt_main.run (
    let* () = Utils.create_dir Globals.global_results_dir in
    if Options.config.file = ""
    then Lwt.return (Options.usage ())
    else
    if Sys.is_directory Options.config.file
    then Lwt_list.iter_s run (Array.to_list @@ Utils.sys_readdir Options.config.file)
    else run Options.config.file
  )
