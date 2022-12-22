(**************************************************************************)
(*                                                                        *)
(*    Copyright 2022 OCamlPro SAS                                         *)
(*                                                                        *)
(*  All rights reserved. This file is distributed under the terms of the  *)
(*  GNU General Public License version 3.0, as described in the LICENSE   *)
(*  file in the root directory of this source tree.                       *)
(*                                                                        *)
(**************************************************************************)

type t = {
  mutable debug: bool;
  mutable file: string;
  mutable timeout: string;
  mutable search: string;
}

let config = {
  debug = false;
  file = "";
  timeout = "10";
  search = "random-path";
}

let arg_usage = "klee4labels FILE [OPTIONS]\n"

let arg_list = Arg.[
    "--debug",
    Unit (fun () -> config.debug <- true),
    "Activates debug messages.";

    "--timeout",
    String (fun t_o -> config.timeout <- t_o),
    "Sets klee timeout (default: 10). 0 means no timeout.";

    "--search",
    String (fun s -> config.search <- s),
    "Uses the dfs search mode for klee. If this mode is set with a klee \
     timeout, labels will be set as covered if they are coverable but may not \
     be associated to actual tests."
  ]

let anon_fun s = config.file <- s

let usage () = Arg.usage arg_list arg_usage

let init () = Arg.parse_argv Sys.argv arg_list anon_fun arg_usage

module Feedback = struct
  open Format
  module type S = sig
    val print : ('a, formatter, unit) format -> 'a
    val debug : ('a, formatter, unit) format -> 'a
  end

  let build (header : string) : (module S) =
    (module struct
      let print fmt =
        printf "[%s] " header;
        printf fmt

      let debug fmt =
        (if config.debug
         then print
         else ifprintf std_formatter) fmt
    end)
end
