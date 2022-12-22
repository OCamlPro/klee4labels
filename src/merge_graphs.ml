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
open Types

let filter = ref None

let final_file_name () =
  match !filter with
  | None -> "global_chart.py"
  | Some f -> Format.sprintf "global_chart_%s.py" f

let init () =
  if Array.length Sys.argv <= 1
  then let () =
         Format.eprintf "Working on the whole %s directrory@."
           Globals.global_results_dir in ()
  else
    filter := Some (Sys.argv.(1))

module IntSet = Set.Make(Int)
module FlagMap = Map.Make(Flag)

type relative_label = {
  relative_label : float;
  relative_time: float;
}

type relative_results = {
  flag : Flag.t;
  (* number_tests: int; *)
  rel_labels : relative_label list
}

type stats = {
  (* total_labels: int; *)
  (* max_time: float; *)
  rel_results: relative_results list
}

type flagged_stats = relative_label list list FlagMap.t

type merged_stats = relative_label list FlagMap.t

let (//) = Filename.concat

let get_results () =
  let results_dir =
    try
      Array.to_list @@ Sys.readdir Globals.global_results_dir
    with Sys_error _ -> Format.eprintf "Error while reading directory %s@." Globals.global_results_dir; []
  in
  let projs =
    match !filter with
    | None ->
      Format.eprintf "Working on the whole %s directrory@." Globals.global_results_dir;
      results_dir
    | Some str ->
      List.filter (
        let rgxp = Str.regexp str in
        fun dir ->
          let res =
            try ignore @@ Str.search_forward rgxp dir 0; true
            with Not_found -> false in
          if not res then Format.eprintf "Ignoring %s@." dir;
          res
      )
        results_dir
  in

  List.filter_map (fun dir ->
      let full_file = Globals.global_results_dir // dir // Globals.json_results in
      if Sys.file_exists full_file
      then Some (Plot.read_json_results_from_file full_file)
      else None
    ) projs

let num_tests_of_result result =
  let filter =
    match Results.get_flag result with
    | Flag.Optimized -> fun (_, tk) -> tk = TestKind.Assert
    | _ -> fun (_, tk) -> tk = TestKind.Ktest
  in List.length @@ List.filter filter result.Results.tests_generated

let result_to_relative_results
    _flag
    total_labels
    max_time
    number_tests
    (results : Results.t) : relative_label list =
  let total_labels = float_of_int total_labels in
  let labels_covered = List.fast_sort (fun (_, t) (_, t') -> Float.compare t t') results.labels_covered in
  let _number_tests = float_of_int number_tests in
  (* Format.eprintf "Flag: %s(tests; %f)@." (Flag.to_string flag) number_tests; *)
  {relative_label = 0.; relative_time = 0.} ::
  List.mapi (fun i (_label, time) ->
      (* Format.eprintf "%i labels after %f time. Score: %f, %f@." i time ((float_of_int i /. (total_labels *. number_tests)) *. 100.) ((time /. max_time) *. 100.); *)
      { relative_label = (float_of_int i /. (total_labels (* *. number_tests *))) *. 100.;
        relative_time = (time /. max_time) *. 100.}
    ) labels_covered

let all_labels_of_results (results : Results.t list) : IntSet.t =
  List.fold_left (fun acc result ->
      List.fold_left
        (fun acc (i, _) -> IntSet.add i acc)
        acc
        result.Results.labels_covered
    ) IntSet.empty results

let max_time (results : Results.t list) : float =
  List.fold_left
    (fun m results ->
       List.fold_left (fun m (_,time) -> if m >= time then m else time) m results.Results.labels_covered
    ) 0. results

let results_to_stats (results : Results.t list) =
  let total_labels =
    let labels = all_labels_of_results results in
    IntSet.cardinal labels
  in

  let max_time = max_time results in

  let rel_results = List.map (fun (result : Results.t) ->
      let number_tests = num_tests_of_result result in
      {
        flag = Results.get_flag result;
        (* number_tests; *)
        rel_labels = result_to_relative_results (Results.get_flag result) total_labels max_time number_tests result;
      }
    ) results
  in
  {(* total_labels; *)
   (* max_time; *)
   rel_results
  }

let add_to_map map (relative_res : relative_results) =
  match FlagMap.find_opt relative_res.flag map with
  | None -> FlagMap.add relative_res.flag [relative_res.rel_labels] map
  | Some l -> FlagMap.add relative_res.flag (relative_res.rel_labels :: l) map

let to_flag_map stats =
  List.fold_left
    (fun map stat -> List.fold_left add_to_map map stat.rel_results)
    FlagMap.empty
    stats

(* Time consuming, consider map of time -> num of labels *)
let labels_covered_at_time ~time label_list =
  let rec loop = function
    | [{relative_label; _}] -> relative_label
    | [] -> assert false
    |
      {relative_label = l1; relative_time = t1} ::
      ({relative_time = t2; relative_label=l2} :: _ as tl) ->
      if time >= t1 && time <= t2
      then if time = t2 then l2 else l1
      else loop tl
  in let res = loop label_list in
  res

let precision = 100.
let delta = 0.1


(* For i in 0..precision, will calculate the mean of labels covered
   at time i. For relative labels, time is in percentage. *)
let merge_charts _flag (rll : relative_label list list) : relative_label list =
  let size = float_of_int @@ List.length rll in
  (* Format.eprintf "Flag: %s@." (Flag.to_string _flag); *)
  let rec loop res time =
    if time > precision then List.rev res else
      let rel_labels = List.map (labels_covered_at_time ~time) rll in
      let mean =  (List.fold_left (+.) 0. rel_labels) /. size in
      (* Format.eprintf "At time %f, a mean of %f labels have been covered@." time mean; *)
      let new_res = {
        relative_label = mean;
        relative_time = time
      } :: res in loop new_res (time +. delta)
  in loop [] 0.

let merge_stats_map (fs : flagged_stats) : merged_stats =
  FlagMap.mapi merge_charts fs

let relative_labels_to_data style list =
  let revx, revy =
    List.fold_left
      (fun (x, y) {relative_time; relative_label} ->
         relative_time :: x, relative_label :: y
      ) ([],[]) list
  in
  Plot.{style; x = List.rev revx; y = List.rev revy}

let merged_stats_to_chart m =
  let data =
    FlagMap.fold (fun flag l acc ->
        let style = Plot.style_from_flag flag in
        relative_labels_to_data style l :: acc
      ) m []
  in Plot.{
      x_legend = "Time (in percentage)";
      y_legend = "Labels (in percentage) / #tests";
      data
    }

let () =
  let () = init () in
  let results = get_results () in
  let stats = List.map results_to_stats results in
  let stats_map = to_flag_map stats in
  let merged_map = merge_stats_map stats_map in
  let chart = merged_stats_to_chart merged_map in
  Utils.write_in
    (Filename.concat Globals.global_results_dir (final_file_name ()))
    (fun fmt -> Plot.print_chart fmt chart)
