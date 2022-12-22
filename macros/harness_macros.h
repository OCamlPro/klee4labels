/**************************************************************************
 *                                                                        *
 *    Copyright 2022 OCamlPro SAS                                         *
 *                                                                        *
 *  All rights reserved. This file is distributed under the terms of the  *
 *  GNU General Public License version 3.0, as described in the LICENSE   *
 *  file in the root directory of this source tree.                       *
 *                                                                        *
 **************************************************************************/

#include <utils.h>

#ifdef REPLAY
#include <replay.h>
#define HARNESS_START do{klee_make_symbolic(&_nondet, sizeof(int), "_nondet");}while(0)
#define HARNESS_END do{}while(0)
#else // begin

#define HARNESS_START do{klee_make_symbolic(&_nondet, sizeof(int), "_nondet");}while(0)

// Selecting additional modes
#ifdef OPTIMIZED
#define HARNESS_END SILENT_EXIT
#else
#define HARNESS_END do {} while(0)
#endif

// Choosing the cov_label handler
#ifdef IGNORE
#include <ignore.h>
#endif

#ifdef NAIVE
#include <naive.h>
#endif

#ifdef OPTIMIZED
#include <optimized.h>
#endif

// end
#endif
