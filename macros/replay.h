/**************************************************************************
 *                                                                        *
 *    Copyright 2022 OCamlPro SAS                                         *
 *                                                                        *
 *  All rights reserved. This file is distributed under the terms of the  *
 *  GNU General Public License version 3.0, as described in the LICENSE   *
 *  file in the root directory of this source tree.                       *
 *                                                                        *
 **************************************************************************/

void log(char* msg){
  if (getenv("DEBUG")) printf("%s", msg);
}

#define cov_label(expr, id, ...)			\
  do {							\
    if (expr) {						\
      log("This test covers label " TOSTRING(id) "\n");	\
      if (!(IS_COVERED(id))) {				\
	LOG_COVERED_LABEL (id);				\
      }							\
    }							\
  } while (0)
