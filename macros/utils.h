/**************************************************************************
 *                                                                        *
 *    Copyright 2022 OCamlPro SAS                                         *
 *                                                                        *
 *  All rights reserved. This file is distributed under the terms of the  *
 *  GNU General Public License version 3.0, as described in the LICENSE   *
 *  file in the root directory of this source tree.                       *
 *                                                                        *
 **************************************************************************/

#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <assert.h>
#include <klee/klee.h>
#include <time.h>

int _nondet;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define LABEL_FILE(id) EXEC_PATH "" TOSTRING(id) ".lbl"

#ifdef REPLAY
#define NONDET(...) 1
#define IS_COVERED(...) 0
#define ASSERT_EXIT do{}while(0)
#define SILENT_EXIT do{}while(0)
#define ASSUME(...) do{}while(0)
#define LOG_COVERED_LABEL(id) do {		\
    char* fname = LABEL_FILE(id);		\
    if(!is_covered(fname)){			\
      FILE* file = fopen(fname, "w");		\
      if(file != NULL) close(file);		\
    }						\
  } while(0)
#else
#define NONDET(i) klee_int("_nondet" TOSTRING (i))
#define IS_COVERED(id) is_covered(LABEL_FILE(id))
#define ASSERT_EXIT klee_assert(0)
#define SILENT_EXIT klee_silent_exit(0)
#define ASSUME(cond) klee_assume(cond)
#define LOG_COVERED_LABEL(...) do{}while(0)
#endif

int is_covered(char* labelfile){
  FILE* f = fopen(labelfile, "r");
  if (f != NULL) {
    fclose(f);
    return 1;
  }
  return 0;
}


/* --- */

/* Flat variables: */
#define _FLAT(v, vname, typ)		\
  klee_make_symbolic (&v, sizeof (v), vname)

/* Pointers encoding: */
#define _PTR_INDEX_SYMBOL(p, i) __##p##_##i
#define _PTR_LEN(p) __##p##_length
#define _PTR_ADDR(p, i) (&_PTR_INDEX_SYMBOL (p, i))
#define _PTR_IF_INDEX(p, i, code)					\
  do {									\
    if (_PTR_LEN (p) > i)						\
      do code while (0);						\
  } while (0)
#define _PTR_INDEX(p, i, pname, typ)				\
  _PTR_IF_INDEX (p, i, {						\
      klee_make_symbolic (_PTR_ADDR (p, i),			\
			  sizeof (typ),					\
			  pname);					\
    })
#define _PTR_DECL(p, pname)					\
  unsigned int _PTR_LEN (p) =					\
    klee_range (0, _MAX_PTR_ARRAY_LENGTH + 1, pname "$length")
#define _PTR(p)							\
  (_PTR_LEN (p) == 0 ? NULL : _PTR_ADDR (p, 0))
#define _NULL_PTR(p)						\
  do { p = NULL; } while (0)

/* Specific encoding for cstrings: */
#define _CSTRING_SYMBOL(p) __##p##_cstring
#define _CSTRING_NONNULL(p) __##p##_nonnull
#define _CSTRING_IF_NONNULL(p, code)				\
  do {									\
    if (_CSTRING_NONNULL (p))					\
      do code while (0);						\
  } while (0)
#define _CSTRING_FILL(p, pname)					\
  _CSTRING_IF_NONNULL (p, {					\
      klee_make_symbolic (_CSTRING_SYMBOL (p),			\
			  sizeof (char[_MAX_CSTRING_LENGTH + 1]),	\
			  pname /*"[" __TOSTRING (i) "]"*/);		\
      /* enforce last idx is 0; otherwise, use klee_assume? */		\
      /* _CSTRING_SYMBOL (p)[_MAX_CSTRING_LENGTH] = '\000'; */ \
    })
#define _CSTRING_DECL(p, pname)					\
  unsigned int _CSTRING_NONNULL (p) =				\
    klee_range (0, 2, pname "$nonnull")
#define _CSTRING(p)						\
  (_CSTRING_NONNULL (p) == 0 ? NULL : _CSTRING_SYMBOL (p))


#endif
