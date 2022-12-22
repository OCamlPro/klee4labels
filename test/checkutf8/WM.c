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
       cov_label((error == 0 || i < n) != (error == 0 && i < n),1,"WM COR");
       cov_label((error != 0) != (error == 0),2,"WM ROR");
       cov_label(error < 0,3,"WM ABS");
       cov_label((i <= n) != (i < n),4,"WM ROR");
       cov_label((i > n) != (i < n),5,"WM ROR");
       cov_label((i >= n) != (i < n),6,"WM ROR");
       cov_label(i < 0,7,"WM ABS");
       cov_label(n < 0,8,"WM ABS");
       if (! (error == 0 && i < n)) break;
       {
         unsigned char c = (unsigned char)*(buffer + i);
         unsigned int codepoint = (unsigned int)0;
         cov_label(((int)c <= 128) != ((int)c < 128),9,"WM ROR");
         cov_label(((int)c > 128) != ((int)c < 128),10,"WM ROR");
         cov_label(((int)c >= 128) != ((int)c < 128),11,"WM ROR");
         if ((int)c < 128) codepoint = (unsigned int)c;
         else {
           cov_label(((int)c >= 192 || (int)c < 224) != ((int)c >= 192 && 
                                                        (int)c < 224),12,
                    "WM COR");
           cov_label(((int)c < 192) != ((int)c >= 192),13,"WM ROR");
           cov_label(((int)c <= 192) != ((int)c >= 192),14,"WM ROR");
           cov_label(((int)c > 192) != ((int)c >= 192),15,"WM ROR");
           cov_label(((int)c <= 224) != ((int)c < 224),16,"WM ROR");
           cov_label(((int)c > 224) != ((int)c < 224),17,"WM ROR");
           cov_label(((int)c >= 224) != ((int)c < 224),18,"WM ROR");
           if ((int)c >= 192 && (int)c < 224) {
             codepoint = (unsigned int)((int)c - 192);
             cov_label((i + 1 <= n) != (i + 1 < n),19,"WM ROR");
             cov_label((i + 1 > n) != (i + 1 < n),20,"WM ROR");
             cov_label((i + 1 >= n) != (i + 1 < n),21,"WM ROR");
             cov_label(i * 1 != i + 1,22,"WM AOR");
             cov_label(i / 1 != i + 1,23,"WM AOR");
             cov_label(i - 1 != i + 1,24,"WM AOR");
             cov_label(i < 0,25,"WM ABS");
             cov_label(n < 0,26,"WM ABS");
             if (i + 1 < n) {
               cov_label(i * 1 != i + 1,27,"WM AOR");
               cov_label(i / 1 != i + 1,28,"WM AOR");
               cov_label(i - 1 != i + 1,29,"WM AOR");
               cov_label(i < 0,30,"WM ABS");
               i ++;
               c = (unsigned char)*(buffer + i);
               cov_label(((int)c >= 128 || (int)c < 192) != ((int)c >= 128 && 
                                                            (int)c < 192),31,
                        "WM COR");
               cov_label(((int)c < 128) != ((int)c >= 128),32,"WM ROR");
               cov_label(((int)c <= 128) != ((int)c >= 128),33,"WM ROR");
               cov_label(((int)c > 128) != ((int)c >= 128),34,"WM ROR");
               cov_label(((int)c <= 192) != ((int)c < 192),35,"WM ROR");
               cov_label(((int)c > 192) != ((int)c < 192),36,"WM ROR");
               cov_label(((int)c >= 192) != ((int)c < 192),37,"WM ROR");
               if ((int)c >= 128 && (int)c < 192) {
                 cov_label((codepoint * (unsigned int)64) * (unsigned int)(
                          (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                           (int)c - 128),38,"WM AOR");
                 cov_label((codepoint * (unsigned int)64) / (unsigned int)(
                          (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                           (int)c - 128),39,"WM AOR");
                 cov_label(codepoint * (unsigned int)64 - (unsigned int)(
                          (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                           (int)c - 128),40,"WM AOR");
                 cov_label(codepoint / (unsigned int)64 != codepoint * (unsigned int)64,
                          41,"WM AOR");
                 cov_label(codepoint + (unsigned int)64 != codepoint * (unsigned int)64,
                          42,"WM AOR");
                 cov_label(codepoint - (unsigned int)64 != codepoint * (unsigned int)64,
                          43,"WM AOR");
                 cov_label(codepoint < 0,44,"WM ABS");
                 codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                             (int)c - 128);
               }
               else error = 2;
             }
             else error = 5;
           }
           else {
             cov_label(((int)c >= 224 || (int)c < 240) != ((int)c >= 224 && 
                                                          (int)c < 240),45,
                      "WM COR");
             cov_label(((int)c < 224) != ((int)c >= 224),46,"WM ROR");
             cov_label(((int)c <= 224) != ((int)c >= 224),47,"WM ROR");
             cov_label(((int)c > 224) != ((int)c >= 224),48,"WM ROR");
             cov_label(((int)c <= 240) != ((int)c < 240),49,"WM ROR");
             cov_label(((int)c > 240) != ((int)c < 240),50,"WM ROR");
             cov_label(((int)c >= 240) != ((int)c < 240),51,"WM ROR");
             if ((int)c >= 224 && (int)c < 240) {
               codepoint = (unsigned int)((int)c - 224);
               cov_label((i + 2 <= n) != (i + 2 < n),52,"WM ROR");
               cov_label((i + 2 > n) != (i + 2 < n),53,"WM ROR");
               cov_label((i + 2 >= n) != (i + 2 < n),54,"WM ROR");
               cov_label(i * 2 != i + 2,55,"WM AOR");
               cov_label(i / 2 != i + 2,56,"WM AOR");
               cov_label(i - 2 != i + 2,57,"WM AOR");
               cov_label(i < 0,58,"WM ABS");
               cov_label(n < 0,59,"WM ABS");
               if (i + 2 < n) {
                 cov_label(i * 1 != i + 1,60,"WM AOR");
                 cov_label(i / 1 != i + 1,61,"WM AOR");
                 cov_label(i - 1 != i + 1,62,"WM AOR");
                 cov_label(i < 0,63,"WM ABS");
                 i ++;
                 c = (unsigned char)*(buffer + i);
                 cov_label(((int)c >= 128 || (int)c < 192) != ((int)c >= 128 && 
                                                              (int)c < 192),
                          64,"WM COR");
                 cov_label(((int)c < 128) != ((int)c >= 128),65,"WM ROR");
                 cov_label(((int)c <= 128) != ((int)c >= 128),66,"WM ROR");
                 cov_label(((int)c > 128) != ((int)c >= 128),67,"WM ROR");
                 cov_label(((int)c <= 192) != ((int)c < 192),68,"WM ROR");
                 cov_label(((int)c > 192) != ((int)c < 192),69,"WM ROR");
                 cov_label(((int)c >= 192) != ((int)c < 192),70,"WM ROR");
                 if ((int)c >= 128 && (int)c < 192) {
                   cov_label((codepoint * (unsigned int)64) * (unsigned int)(
                            (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                             (int)c - 128),71,"WM AOR");
                   cov_label((codepoint * (unsigned int)64) / (unsigned int)(
                            (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                             (int)c - 128),72,"WM AOR");
                   cov_label(codepoint * (unsigned int)64 - (unsigned int)(
                            (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                             (int)c - 128),73,"WM AOR");
                   cov_label(codepoint / (unsigned int)64 != codepoint * (unsigned int)64,
                            74,"WM AOR");
                   cov_label(codepoint + (unsigned int)64 != codepoint * (unsigned int)64,
                            75,"WM AOR");
                   cov_label(codepoint - (unsigned int)64 != codepoint * (unsigned int)64,
                            76,"WM AOR");
                   cov_label(codepoint < 0,77,"WM ABS");
                   codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                               (int)c - 128);
                   cov_label(i * 1 != i + 1,78,"WM AOR");
                   cov_label(i / 1 != i + 1,79,"WM AOR");
                   cov_label(i - 1 != i + 1,80,"WM AOR");
                   cov_label(i < 0,81,"WM ABS");
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label(((int)c >= 128 || (int)c < 192) != ((int)c >= 128 && 
                                                                (int)c < 192),
                            82,"WM COR");
                   cov_label(((int)c < 128) != ((int)c >= 128),83,"WM ROR");
                   cov_label(((int)c <= 128) != ((int)c >= 128),84,"WM ROR");
                   cov_label(((int)c > 128) != ((int)c >= 128),85,"WM ROR");
                   cov_label(((int)c <= 192) != ((int)c < 192),86,"WM ROR");
                   cov_label(((int)c > 192) != ((int)c < 192),87,"WM ROR");
                   cov_label(((int)c >= 192) != ((int)c < 192),88,"WM ROR");
                   if ((int)c >= 128 && (int)c < 192) {
                     cov_label((codepoint * (unsigned int)64) * (unsigned int)(
                              (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                               (int)c - 128),89,"WM AOR");
                     cov_label((codepoint * (unsigned int)64) / (unsigned int)(
                              (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                               (int)c - 128),90,"WM AOR");
                     cov_label(codepoint * (unsigned int)64 - (unsigned int)(
                              (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                               (int)c - 128),91,"WM AOR");
                     cov_label(codepoint / (unsigned int)64 != codepoint * (unsigned int)64,
                              92,"WM AOR");
                     cov_label(codepoint + (unsigned int)64 != codepoint * (unsigned int)64,
                              93,"WM AOR");
                     cov_label(codepoint - (unsigned int)64 != codepoint * (unsigned int)64,
                              94,"WM AOR");
                     cov_label(codepoint < 0,95,"WM ABS");
                     codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                 (int)c - 128);
                   }
                   else error = 3;
                 }
                 else error = 2;
               }
               else error = 5;
             }
             else {
               cov_label(((int)c >= 240 || (int)c < 248) != ((int)c >= 240 && 
                                                            (int)c < 248),96,
                        "WM COR");
               cov_label(((int)c < 240) != ((int)c >= 240),97,"WM ROR");
               cov_label(((int)c <= 240) != ((int)c >= 240),98,"WM ROR");
               cov_label(((int)c > 240) != ((int)c >= 240),99,"WM ROR");
               cov_label(((int)c <= 248) != ((int)c < 248),100,"WM ROR");
               cov_label(((int)c > 248) != ((int)c < 248),101,"WM ROR");
               cov_label(((int)c >= 248) != ((int)c < 248),102,"WM ROR");
               if ((int)c >= 240 && (int)c < 248) {
                 codepoint = (unsigned int)((int)c - 240);
                 cov_label((i + 3 <= n) != (i + 3 < n),103,"WM ROR");
                 cov_label((i + 3 > n) != (i + 3 < n),104,"WM ROR");
                 cov_label((i + 3 >= n) != (i + 3 < n),105,"WM ROR");
                 cov_label(i * 3 != i + 3,106,"WM AOR");
                 cov_label(i / 3 != i + 3,107,"WM AOR");
                 cov_label(i - 3 != i + 3,108,"WM AOR");
                 cov_label(i < 0,109,"WM ABS");
                 cov_label(n < 0,110,"WM ABS");
                 if (i + 3 < n) {
                   cov_label(i * 1 != i + 1,111,"WM AOR");
                   cov_label(i / 1 != i + 1,112,"WM AOR");
                   cov_label(i - 1 != i + 1,113,"WM AOR");
                   cov_label(i < 0,114,"WM ABS");
                   i ++;
                   c = (unsigned char)*(buffer + i);
                   cov_label(((int)c >= 128 || (int)c < 192) != ((int)c >= 128 && 
                                                                (int)c < 192),
                            115,"WM COR");
                   cov_label(((int)c < 128) != ((int)c >= 128),116,"WM ROR");
                   cov_label(((int)c <= 128) != ((int)c >= 128),117,"WM ROR");
                   cov_label(((int)c > 128) != ((int)c >= 128),118,"WM ROR");
                   cov_label(((int)c <= 192) != ((int)c < 192),119,"WM ROR");
                   cov_label(((int)c > 192) != ((int)c < 192),120,"WM ROR");
                   cov_label(((int)c >= 192) != ((int)c < 192),121,"WM ROR");
                   if ((int)c >= 128 && (int)c < 192) {
                     cov_label((codepoint * (unsigned int)64) * (unsigned int)(
                              (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                               (int)c - 128),122,"WM AOR");
                     cov_label((codepoint * (unsigned int)64) / (unsigned int)(
                              (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                               (int)c - 128),123,"WM AOR");
                     cov_label(codepoint * (unsigned int)64 - (unsigned int)(
                              (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                               (int)c - 128),124,"WM AOR");
                     cov_label(codepoint / (unsigned int)64 != codepoint * (unsigned int)64,
                              125,"WM AOR");
                     cov_label(codepoint + (unsigned int)64 != codepoint * (unsigned int)64,
                              126,"WM AOR");
                     cov_label(codepoint - (unsigned int)64 != codepoint * (unsigned int)64,
                              127,"WM AOR");
                     cov_label(codepoint < 0,128,"WM ABS");
                     codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                 (int)c - 128);
                     cov_label(i * 1 != i + 1,129,"WM AOR");
                     cov_label(i / 1 != i + 1,130,"WM AOR");
                     cov_label(i - 1 != i + 1,131,"WM AOR");
                     cov_label(i < 0,132,"WM ABS");
                     i ++;
                     c = (unsigned char)*(buffer + i);
                     cov_label(((int)c >= 128 || (int)c < 192) != ((int)c >= 128 && 
                                                                  (int)c < 192),
                              133,"WM COR");
                     cov_label(((int)c < 128) != ((int)c >= 128),134,"WM ROR");
                     cov_label(((int)c <= 128) != ((int)c >= 128),135,
                              "WM ROR");
                     cov_label(((int)c > 128) != ((int)c >= 128),136,"WM ROR");
                     cov_label(((int)c <= 192) != ((int)c < 192),137,"WM ROR");
                     cov_label(((int)c > 192) != ((int)c < 192),138,"WM ROR");
                     cov_label(((int)c >= 192) != ((int)c < 192),139,"WM ROR");
                     if ((int)c >= 128 && (int)c < 192) {
                       cov_label((codepoint * (unsigned int)64) * (unsigned int)(
                                (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                                 (int)c - 128),140,"WM AOR");
                       cov_label((codepoint * (unsigned int)64) / (unsigned int)(
                                (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                                 (int)c - 128),141,"WM AOR");
                       cov_label(codepoint * (unsigned int)64 - (unsigned int)(
                                (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                                 (int)c - 128),142,"WM AOR");
                       cov_label(codepoint / (unsigned int)64 != codepoint * (unsigned int)64,
                                143,"WM AOR");
                       cov_label(codepoint + (unsigned int)64 != codepoint * (unsigned int)64,
                                144,"WM AOR");
                       cov_label(codepoint - (unsigned int)64 != codepoint * (unsigned int)64,
                                145,"WM AOR");
                       cov_label(codepoint < 0,146,"WM ABS");
                       codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                   (int)c - 128);
                       cov_label(i * 1 != i + 1,147,"WM AOR");
                       cov_label(i / 1 != i + 1,148,"WM AOR");
                       cov_label(i - 1 != i + 1,149,"WM AOR");
                       cov_label(i < 0,150,"WM ABS");
                       i ++;
                       c = (unsigned char)*(buffer + i);
                       cov_label(((int)c >= 128 || (int)c < 192) != ((int)c >= 128 && 
                                                                    (int)c < 192),
                                151,"WM COR");
                       cov_label(((int)c < 128) != ((int)c >= 128),152,
                                "WM ROR");
                       cov_label(((int)c <= 128) != ((int)c >= 128),153,
                                "WM ROR");
                       cov_label(((int)c > 128) != ((int)c >= 128),154,
                                "WM ROR");
                       cov_label(((int)c <= 192) != ((int)c < 192),155,
                                "WM ROR");
                       cov_label(((int)c > 192) != ((int)c < 192),156,
                                "WM ROR");
                       cov_label(((int)c >= 192) != ((int)c < 192),157,
                                "WM ROR");
                       if ((int)c >= 128 && (int)c < 192) {
                         cov_label((codepoint * (unsigned int)64) * (unsigned int)(
                                  (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                                   (int)c - 128),158,
                                  "WM AOR");
                         cov_label((codepoint * (unsigned int)64) / (unsigned int)(
                                  (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                                   (int)c - 128),159,
                                  "WM AOR");
                         cov_label(codepoint * (unsigned int)64 - (unsigned int)(
                                  (int)c - 128) != codepoint * (unsigned int)64 + (unsigned int)(
                                                   (int)c - 128),160,
                                  "WM AOR");
                         cov_label(codepoint / (unsigned int)64 != codepoint * (unsigned int)64,
                                  161,"WM AOR");
                         cov_label(codepoint + (unsigned int)64 != codepoint * (unsigned int)64,
                                  162,"WM AOR");
                         cov_label(codepoint - (unsigned int)64 != codepoint * (unsigned int)64,
                                  163,"WM AOR");
                         cov_label(codepoint < 0,164,"WM ABS");
                         codepoint = codepoint * (unsigned int)64 + (unsigned int)(
                                     (int)c - 128);
                       }
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
         cov_label((codepoint > (unsigned int)0xD7FF || codepoint < (unsigned int)0xE000) != (
                  codepoint > (unsigned int)0xD7FF && codepoint < (unsigned int)0xE000),
                  165,"WM COR");
         cov_label((codepoint < (unsigned int)0xD7FF) != (codepoint > (unsigned int)0xD7FF),
                  166,"WM ROR");
         cov_label((codepoint <= (unsigned int)0xD7FF) != (codepoint > (unsigned int)0xD7FF),
                  167,"WM ROR");
         cov_label((codepoint >= (unsigned int)0xD7FF) != (codepoint > (unsigned int)0xD7FF),
                  168,"WM ROR");
         cov_label(codepoint < 0,169,"WM ABS");
         cov_label((codepoint <= (unsigned int)0xE000) != (codepoint < (unsigned int)0xE000),
                  170,"WM ROR");
         cov_label((codepoint > (unsigned int)0xE000) != (codepoint < (unsigned int)0xE000),
                  171,"WM ROR");
         cov_label((codepoint >= (unsigned int)0xE000) != (codepoint < (unsigned int)0xE000),
                  172,"WM ROR");
         cov_label(codepoint < 0,173,"WM ABS");
         if (codepoint > (unsigned int)0xD7FF && codepoint < (unsigned int)0xE000) 
           error = 6;
       }
       cov_label(i * 1 != i + 1,174,"WM AOR");
       cov_label(i / 1 != i + 1,175,"WM AOR");
       cov_label(i - 1 != i + 1,176,"WM AOR");
       cov_label(i < 0,177,"WM ABS");
       i ++;
     }
   }
   cov_label(error < 0,178,"WM ABS");
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
