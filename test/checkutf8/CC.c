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
       cov_label(error == 0,1,"CC");
       cov_label(! (error == 0),2,"CC");
       cov_label(i < n,3,"CC");
       cov_label(! (i < n),4,"CC");
       if (! (error == 0 && i < n)) break;
       {
         unsigned char c = (unsigned char)*(buffer + i);
         unsigned int codepoint = (unsigned int)0;
         cov_label((int)c < 128,5,"CC");
         cov_label(! ((int)c < 128),6,"CC");
         if ((int)c < 128) codepoint = (unsigned int)c;
         else {
           cov_label((int)c >= 192,7,"CC");
           cov_label(! ((int)c >= 192),8,"CC");
           cov_label((int)c < 224,9,"CC");
           cov_label(! ((int)c < 224),10,"CC");
           if ((int)c >= 192 && (int)c < 224) {
             codepoint = (unsigned int)((int)c - 192);
             cov_label(i + 1 < n,11,"CC");
             cov_label(! (i + 1 < n),12,"CC");
             if (i + 1 < n) {
               i ++;
               c = (unsigned char)*(buffer + i);
               cov_label((int)c >= 128,13,"CC");
               cov_label(! ((int)c >= 128),14,"CC");
               cov_label((int)c < 192,15,"CC");
               cov_label(! ((int)c < 192),16,"CC");
               if ((int)c >= 128 && (int)c < 192) codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                                              (int)c - 128);
               else error = 2;
             }
             else error = 5;
           }
           else {
             cov_label((int)c >= 224,17,"CC");
             cov_label(! ((int)c >= 224),18,"CC");
             cov_label((int)c < 240,19,"CC");
             cov_label(! ((int)c < 240),20,"CC");
             if ((int)c >= 224 && (int)c < 240) {
               codepoint = (unsigned int)((int)c - 224);
               cov_label(i + 2 < n,21,"CC");
               cov_label(! (i + 2 < n),22,"CC");
               if (i + 2 < n) {
                 i ++;
                 c = (unsigned char)*(buffer + i);
                 cov_label((int)c >= 128,23,"CC");
                 cov_label(! ((int)c >= 128),24,"CC");
                 cov_label((int)c < 192,25,"CC");
                 cov_label(! ((int)c < 192),26,"CC");
                 if ((int)c >= 128 && (int)c < 192) {
                   codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                               (int)c - 128);
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label((int)c >= 128,27,"CC");
                   cov_label(! ((int)c >= 128),28,"CC");
                   cov_label((int)c < 192,29,"CC");
                   cov_label(! ((int)c < 192),30,"CC");
                   if ((int)c >= 128 && (int)c < 192) codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                                                  (int)c - 128);
                   else error = 3;
                 }
                 else error = 2;
               }
               else error = 5;
             }
             else {
               cov_label((int)c >= 240,31,"CC");
               cov_label(! ((int)c >= 240),32,"CC");
               cov_label((int)c < 248,33,"CC");
               cov_label(! ((int)c < 248),34,"CC");
               if ((int)c >= 240 && (int)c < 248) {
                 codepoint = (unsigned int)((int)c - 240);
                 cov_label(i + 3 < n,35,"CC");
                 cov_label(! (i + 3 < n),36,"CC");
                 if (i + 3 < n) {
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label((int)c >= 128,37,"CC");
                   cov_label(! ((int)c >= 128),38,"CC");
                   cov_label((int)c < 192,39,"CC");
                   cov_label(! ((int)c < 192),40,"CC");
                   if ((int)c >= 128 && (int)c < 192) {
                     codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                 (int)c - 128);
                     i ++;
                     c = (unsigned char)*(buffer + i);
                     cov_label((int)c >= 128,41,"CC");
                     cov_label(! ((int)c >= 128),42,"CC");
                     cov_label((int)c < 192,43,"CC");
                     cov_label(! ((int)c < 192),44,"CC");
                     if ((int)c >= 128 && (int)c < 192) {
                       codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                   (int)c - 128);
                       i ++;
                       c = (unsigned char)*(buffer + i);
                       cov_label((int)c >= 128,45,"CC");
                       cov_label(! ((int)c >= 128),46,"CC");
                       cov_label((int)c < 192,47,"CC");
                       cov_label(! ((int)c < 192),48,"CC");
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
         cov_label(codepoint > (unsigned int)0xD7FF,49,"CC");
         cov_label(! (codepoint > (unsigned int)0xD7FF),50,"CC");
         cov_label(codepoint < (unsigned int)0xE000,51,"CC");
         cov_label(! (codepoint < (unsigned int)0xE000),52,"CC");
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
