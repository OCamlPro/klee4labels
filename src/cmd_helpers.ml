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
open Utils

let compile_replayer_cmd libs file output =
  Format.asprintf
    "clang -DREPLAY %a -DEXEC_PATH='\"%s/\"' %s -lkleeRuntest -o %s"
    print_lib_paths libs
    (Filename.dirname output)
    file
    output

let compile_llvm_cmd flag libs file output =
  let flags =
    let exec_path =
      let path = Filename.dirname output in
      Format.sprintf "EXEC_PATH='\"%s/\"'" path
    in
    let sflag = Types.Flag.to_string flag in
    [exec_path; sflag]
  in
  Format.asprintf
    "clang -emit-llvm %a %a -c %s -o %s"
    print_flags flags
    print_lib_paths libs
    file
    output

type klee_cmd = {
  cmd : string;
  output_dir : string;
}

let start_klee_cmd llvm_file : klee_cmd =
  let output_dir =
    let llvm_basename = Filename.basename llvm_file in
    let llvm_dirname = Filename.dirname llvm_file in
    Filename.(
      concat
        llvm_dirname
        (Format.sprintf "klee-out-%s" (chop_extension llvm_basename)))
  in
  let max_time = Options.config.timeout in
  let other = ["--only-output-states-covering-new"; (* "--libc=uclibc" ; *) "--watchdog"] in
  {
    cmd = Format.asprintf
        "klee --search=%s --entry-point=main --output-dir=%s %a --max-time=%s %s"
        Options.config.search
        output_dir
        (print_str_list ~sep:" ") other
        max_time
        llvm_file;
    output_dir
  }

let replay_cmd ktest_file executable : string =
  Format.sprintf "KTEST_FILE=%s %s" ktest_file executable

type exec_details = {
  exec_time: float;
  process_status: Unix.process_status;
}

let handle_unix_status cmd cont res = match res.process_status with
  | Unix.WEXITED 0 -> cont res
  | WEXITED i -> failwith "Unexpected exit (code %i; cmd: %s)" i cmd
  | WSIGNALED i -> failwith "Signal %i has shut down the replayer compilation; cmd: %s" i cmd
  | WSTOPPED i -> failwith "Replayer compilation unexpectedly exited with code %i; cmd: %s" i cmd

let exec_cmd cmd =
  let now = Unix.gettimeofday () in
  let* process_status =
    Lwt_process.(exec ~stderr:`Dev_null @@ shell cmd)
  in
  let exec_time = Unix.gettimeofday () -. now in
  Lwt.return {exec_time; process_status}

module Syntax = struct
  let (let>?) cmd cont =
    Feedback.debug "Executing cmd %s@." cmd;
    let* status = exec_cmd cmd in
    cont status

  let (let>!) cmd cont =
    let>? res = cmd in
    handle_unix_status cmd cont res
end
