#include "errno.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int check(char *buffer, int n)
 {
   int error = 0;
   {
     int i = 0;
     while (1) {
       cov_label(error == 0 && i < n,1,"MCC");
       cov_label(error == 0 && ! (i < n),2,"MCC");
       cov_label(! (error == 0) && i < n,3,"MCC");
       cov_label(! (error == 0) && ! (i < n),4,"MCC");
       if (! (error == 0 && i < n)) break;
       {
         unsigned char c = (unsigned char)*(buffer + i);
         unsigned int codepoint = (unsigned int)0;
         cov_label((int)c < 128,5,"MCC");
         cov_label(! ((int)c < 128),6,"MCC");
         if ((int)c < 128) codepoint = (unsigned int)c;
         else {
           cov_label((int)c >= 192 && (int)c < 224,7,"MCC");
           cov_label((int)c >= 192 && ! ((int)c < 224),8,"MCC");
           cov_label(! ((int)c >= 192) && (int)c < 224,9,"MCC");
           cov_label(! ((int)c >= 192) && ! ((int)c < 224),10,"MCC");
           if ((int)c >= 192 && (int)c < 224) {
             codepoint = (unsigned int)((int)c - 192);
             cov_label(i + 1 < n,11,"MCC");
             cov_label(! (i + 1 < n),12,"MCC");
             if (i + 1 < n) {
               i ++;
               c = (unsigned char)*(buffer + i);
               cov_label((int)c >= 128 && (int)c < 192,13,"MCC");
               cov_label((int)c >= 128 && ! ((int)c < 192),14,"MCC");
               cov_label(! ((int)c >= 128) && (int)c < 192,15,"MCC");
               cov_label(! ((int)c >= 128) && ! ((int)c < 192),16,"MCC");
               if ((int)c >= 128 && (int)c < 192) codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                                              (int)c - 128);
               else error = 2;
             }
             else error = 5;
           }
           else {
             cov_label((int)c >= 224 && (int)c < 240,17,"MCC");
             cov_label((int)c >= 224 && ! ((int)c < 240),18,"MCC");
             cov_label(! ((int)c >= 224) && (int)c < 240,19,"MCC");
             cov_label(! ((int)c >= 224) && ! ((int)c < 240),20,"MCC");
             if ((int)c >= 224 && (int)c < 240) {
               codepoint = (unsigned int)((int)c - 224);
               cov_label(i + 2 < n,21,"MCC");
               cov_label(! (i + 2 < n),22,"MCC");
               if (i + 2 < n) {
                 i ++;
                 c = (unsigned char)*(buffer + i);
                 cov_label((int)c >= 128 && (int)c < 192,23,"MCC");
                 cov_label((int)c >= 128 && ! ((int)c < 192),24,"MCC");
                 cov_label(! ((int)c >= 128) && (int)c < 192,25,"MCC");
                 cov_label(! ((int)c >= 128) && ! ((int)c < 192),26,"MCC");
                 if ((int)c >= 128 && (int)c < 192) {
                   codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                               (int)c - 128);
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label((int)c >= 128 && (int)c < 192,27,"MCC");
                   cov_label((int)c >= 128 && ! ((int)c < 192),28,"MCC");
                   cov_label(! ((int)c >= 128) && (int)c < 192,29,"MCC");
                   cov_label(! ((int)c >= 128) && ! ((int)c < 192),30,"MCC");
                   if ((int)c >= 128 && (int)c < 192) codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                                                  (int)c - 128);
                   else error = 3;
                 }
                 else error = 2;
               }
               else error = 5;
             }
             else {
               cov_label((int)c >= 240 && (int)c < 248,31,"MCC");
               cov_label((int)c >= 240 && ! ((int)c < 248),32,"MCC");
               cov_label(! ((int)c >= 240) && (int)c < 248,33,"MCC");
               cov_label(! ((int)c >= 240) && ! ((int)c < 248),34,"MCC");
               if ((int)c >= 240 && (int)c < 248) {
                 codepoint = (unsigned int)((int)c - 240);
                 cov_label(i + 3 < n,35,"MCC");
                 cov_label(! (i + 3 < n),36,"MCC");
                 if (i + 3 < n) {
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label((int)c >= 128 && (int)c < 192,37,"MCC");
                   cov_label((int)c >= 128 && ! ((int)c < 192),38,"MCC");
                   cov_label(! ((int)c >= 128) && (int)c < 192,39,"MCC");
                   cov_label(! ((int)c >= 128) && ! ((int)c < 192),40,"MCC");
                   if ((int)c >= 128 && (int)c < 192) {
                     codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                 (int)c - 128);
                     i ++;
                     c = (unsigned char)*(buffer + i);
                     cov_label((int)c >= 128 && (int)c < 192,41,"MCC");
                     cov_label((int)c >= 128 && ! ((int)c < 192),42,"MCC");
                     cov_label(! ((int)c >= 128) && (int)c < 192,43,"MCC");
                     cov_label(! ((int)c >= 128) && ! ((int)c < 192),44,"MCC");
                     if ((int)c >= 128 && (int)c < 192) {
                       codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                   (int)c - 128);
                       i ++;
                       c = (unsigned char)*(buffer + i);
                       cov_label((int)c >= 128 && (int)c < 192,45,"MCC");
                       cov_label((int)c >= 128 && ! ((int)c < 192),46,"MCC");
                       cov_label(! ((int)c >= 128) && (int)c < 192,47,"MCC");
                       cov_label(! ((int)c >= 128) && ! ((int)c < 192),48,
                                "MCC");
                       if ((int)c >= 128 && (int)c < 192) codepoint = 
                                                          codepoint * (unsigned int)64 + (unsigned int)(
                                                          (int)c - 128);
                       else error = 4;
                     }
                     else error = 3;
                   }
                   else error = 2;
                 }
                 else error = 5;
               }
               else error = 1;
             }
           }
         }
         cov_label(codepoint > 55295U && codepoint < 57344U,49,"MCC");
         cov_label(codepoint > 55295U && ! (codepoint < 57344U),50,"MCC");
         cov_label(! (codepoint > 55295U) && codepoint < 57344U,51,"MCC");
         cov_label(! (codepoint > 55295U) && ! (codepoint < 57344U),52,"MCC");
         if (codepoint > (unsigned int)0xD7FF && codepoint < (unsigned int)0xE000) 
           error = 6;
       }
       i ++;
     }
   }
   return error;
 }


#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 5
static char _CSTRING_SYMBOL (v0)[6]; /* buffer */

int main () {
  int n;
  char (* buffer);

  HARNESS_START;
  _FLAT (n, "n", int);
  _CSTRING_DECL (v0, "buffer");
  _CSTRING_FILL (v0, "buffer");
  buffer = _CSTRING (v0);

  (void) check (buffer, n);
  HARNESS_END;
  return 0;
}

