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
       cov_label(error == 0 && i < n,1,"DC");
       cov_label(! (error == 0 && i < n),2,"DC");
       if (! (error == 0 && i < n)) break;
       {
         unsigned char c = (unsigned char)*(buffer + i);
         unsigned int codepoint = (unsigned int)0;
         cov_label((int)c < 128,3,"DC");
         cov_label(! ((int)c < 128),4,"DC");
         if ((int)c < 128) codepoint = (unsigned int)c;
         else {
           cov_label((int)c >= 192 && (int)c < 224,5,"DC");
           cov_label(! ((int)c >= 192 && (int)c < 224),6,"DC");
           if ((int)c >= 192 && (int)c < 224) {
             codepoint = (unsigned int)((int)c - 192);
             cov_label(i + 1 < n,7,"DC");
             cov_label(! (i + 1 < n),8,"DC");
             if (i + 1 < n) {
               i ++;
               c = (unsigned char)*(buffer + i);
               cov_label((int)c >= 128 && (int)c < 192,9,"DC");
               cov_label(! ((int)c >= 128 && (int)c < 192),10,"DC");
               if ((int)c >= 128 && (int)c < 192) codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                                              (int)c - 128);
               else error = 2;
             }
             else error = 5;
           }
           else {
             cov_label((int)c >= 224 && (int)c < 240,11,"DC");
             cov_label(! ((int)c >= 224 && (int)c < 240),12,"DC");
             if ((int)c >= 224 && (int)c < 240) {
               codepoint = (unsigned int)((int)c - 224);
               cov_label(i + 2 < n,13,"DC");
               cov_label(! (i + 2 < n),14,"DC");
               if (i + 2 < n) {
                 i ++;
                 c = (unsigned char)*(buffer + i);
                 cov_label((int)c >= 128 && (int)c < 192,15,"DC");
                 cov_label(! ((int)c >= 128 && (int)c < 192),16,"DC");
                 if ((int)c >= 128 && (int)c < 192) {
                   codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                               (int)c - 128);
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label((int)c >= 128 && (int)c < 192,17,"DC");
                   cov_label(! ((int)c >= 128 && (int)c < 192),18,"DC");
                   if ((int)c >= 128 && (int)c < 192) codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                                                  (int)c - 128);
                   else error = 3;
                 }
                 else error = 2;
               }
               else error = 5;
             }
             else {
               cov_label((int)c >= 240 && (int)c < 248,19,"DC");
               cov_label(! ((int)c >= 240 && (int)c < 248),20,"DC");
               if ((int)c >= 240 && (int)c < 248) {
                 codepoint = (unsigned int)((int)c - 240);
                 cov_label(i + 3 < n,21,"DC");
                 cov_label(! (i + 3 < n),22,"DC");
                 if (i + 3 < n) {
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label((int)c >= 128 && (int)c < 192,23,"DC");
                   cov_label(! ((int)c >= 128 && (int)c < 192),24,"DC");
                   if ((int)c >= 128 && (int)c < 192) {
                     codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                 (int)c - 128);
                     i ++;
                     c = (unsigned char)*(buffer + i);
                     cov_label((int)c >= 128 && (int)c < 192,25,"DC");
                     cov_label(! ((int)c >= 128 && (int)c < 192),26,"DC");
                     if ((int)c >= 128 && (int)c < 192) {
                       codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                   (int)c - 128);
                       i ++;
                       c = (unsigned char)*(buffer + i);
                       cov_label((int)c >= 128 && (int)c < 192,27,"DC");
                       cov_label(! ((int)c >= 128 && (int)c < 192),28,"DC");
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
         cov_label(codepoint > (unsigned int)0xD7FF && codepoint < (unsigned int)0xE000,
                  29,"DC");
         cov_label(! (codepoint > (unsigned int)0xD7FF && codepoint < (unsigned int)0xE000),
                  30,"DC");
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


