#include "harness_macros.h"
#include "assert.h"
#include "errno.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int modulus(unsigned int n, unsigned int s)
 {
   int __retres;
   unsigned int d;
   unsigned int m;
   d = (unsigned int)((1 << s) - 1);
   cov_label((d < (unsigned int)0) != (d > (unsigned int)0),1,"WM ROR");
   cov_label((d <= (unsigned int)0) != (d > (unsigned int)0),2,"WM ROR");
   cov_label((d >= (unsigned int)0) != (d > (unsigned int)0),3,"WM ROR");
   cov_label(d < 0,4,"WM ABS");
   if (d > (unsigned int)0) {
     cov_label(n < 0,5,"WM ABS");
     m = n;
     while (1) {
       cov_label((n < d) != (n > d),6,"WM ROR");
       cov_label((n <= d) != (n > d),7,"WM ROR");
       cov_label((n >= d) != (n > d),8,"WM ROR");
       cov_label(n < 0,9,"WM ABS");
       cov_label(d < 0,10,"WM ABS");
       if (! (n > d)) break;
       m = (unsigned int)0;
       while (1) {
         cov_label((n < (unsigned int)0) != (n > (unsigned int)0),11,"WM ROR");
         cov_label((n <= (unsigned int)0) != (n > (unsigned int)0),12,
                  "WM ROR");
         cov_label((n >= (unsigned int)0) != (n > (unsigned int)0),13,
                  "WM ROR");
         cov_label(n < 0,14,"WM ABS");
         if (! (n > (unsigned int)0)) break;
         cov_label(m * (n & d) != m + (n & d),15,"WM AOR");
         cov_label(m / (n & d) != m + (n & d),16,"WM AOR");
         cov_label(m - (n & d) != m + (n & d),17,"WM AOR");
         cov_label(m < 0,18,"WM ABS");
         cov_label(n < 0,19,"WM ABS");
         cov_label(d < 0,20,"WM ABS");
         m += n & d;
         cov_label(n << s != n >> s,21,"WM AOR");
         cov_label(n < 0,22,"WM ABS");
         cov_label(s < 0,23,"WM ABS");
         n >>= s;
       }
       cov_label(m < 0,24,"WM ABS");
       n = m;
     }
     cov_label((m != d) != (m == d),25,"WM ROR");
     cov_label(m < 0,26,"WM ABS");
     cov_label(d < 0,27,"WM ABS");
     if (m == d) m = (unsigned int)0;
   }
   __retres = (int)m;
   cov_label(__retres < 0,28,"WM ABS");
   return __retres;
 }


#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 20

int main () {
  HARNESS_START;
  unsigned int n;
  unsigned int s;


  _FLAT (n, "n", unsigned int);
  _FLAT (s, "s", unsigned int);

  (void) modulus (n, s);
  HARNESS_END;
  return 0;
}
