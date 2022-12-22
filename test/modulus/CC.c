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
   cov_label(d > (unsigned int)0,1,"CC");
   cov_label(! (d > (unsigned int)0),2,"CC");
   if (d > (unsigned int)0) {
     m = n;
     while (1) {
       cov_label(n > d,3,"CC");
       cov_label(! (n > d),4,"CC");
       if (! (n > d)) break;
       m = (unsigned int)0;
       while (1) {
         cov_label(n > (unsigned int)0,5,"CC");
         cov_label(! (n > (unsigned int)0),6,"CC");
         if (! (n > (unsigned int)0)) break;
         m += n & d;
         n >>= s;
       }
       n = m;
     }
     cov_label(m == d,7,"CC");
     cov_label(! (m == d),8,"CC");
     if (m == d) m = (unsigned int)0;
   }
   __retres = (int)m;
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
