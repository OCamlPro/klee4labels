(**************************************************************************)
(*                                                                        *)
(*    Copyright 2022 OCamlPro SAS                                         *)
(*                                                                        *)
(*  All rights reserved. This file is distributed under the terms of the  *)
(*  GNU General Public License version 3.0, as described in the LICENSE   *)
(*  file in the root directory of this source tree.                       *)
(*                                                                        *)
(**************************************************************************)

open Types

let libname = "matplotlib.pyplot"
let shortname = "plt"

type style = {
  color: string;
  line_style: string;
  label: string;
}

type data = {
  style: style;
  x: float list;
  y: float list;
}

type chart = {
  x_legend: string;
  y_legend: string;
  data: data list;
}

let style_from_flag = function
  | Flag.Ignore -> {
      color = "red";
      line_style="dotted";
      label="Ignore"
    }
  | Naive -> {
      color = "green";
      line_style="dashed";
      label="Naive"
    }
  | Optimized -> {
      color = "blue";
      line_style="solid";
      label="Optimized"
    }

let data_from_result (result : Results.t) =
  let times =
    result.labels_covered
    |> List.split
    |> snd
    |> List.fast_sort Float.compare
    |> List.cons 0.
  in
  let module O = (val result.options) in
  {
    style = style_from_flag O.flag;
    y = List.map float_of_int @@ Utils.range 0 (List.length times - 1);
    x = times
  }

let chart_from_results results = {
  x_legend = "Time";
  y_legend = "Covered labels";
  data = List.map data_from_result results;
}


let print_float_list ~(float_fmt : ('a, Format.formatter, unit) format) fmt =
  Utils.print_list ~sep:"," (fun fmt -> Format.fprintf fmt float_fmt) fmt

let plot_data fmt data =
  Format.fprintf fmt "%s.plot(\
                      [%a],\
                      [%a],\
                      color='%s',\
                      label='%s',\
                      linestyle='%s')@."
    shortname
    (print_float_list ~float_fmt:"%f") data.x
    (print_float_list ~float_fmt:"%f") data.y
    data.style.color
    data.style.label
    data.style.line_style

let print_data fmt data_list =
  List.iter (plot_data fmt) data_list


let print_chart fmt chart =
  Format.fprintf fmt
    "import %s as %s\n\
     %s.xlabel('%s')\n\
     %s.ylabel('%s')\n\
     %a\n\
     %s.legend()\n\
     %s.show()@."
    libname shortname
    shortname chart.x_legend
    shortname chart.y_legend
    print_data chart.data
    shortname
    shortname

let write_chart_in_file results fname =
  let chart = chart_from_results results in
  Utils.write_in fname (fun fmt -> print_chart fmt chart)

let results_encoding = Json_encoding.list Results.enc

module Json_read = Json_encoding.Make(Json_repr.Yojson)

let write_json_results_in_file results fname =
  let json =
    Json_encoding.construct results_encoding results
    |> Json_repr.to_any
  in
  Utils.write_in fname (fun fmt ->
    Json_repr.pp_any () fmt json
  )

let read_json_results_from_file file =
  Yojson.Safe.from_file file |>
  Json_read.destruct results_encoding
