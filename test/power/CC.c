

#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int power(int X, int N)
{
  ASSUME(N <= 100);
  int S = 1;
  int Y = X;
  int P = N;
  while (1) {
    cov_label(P >= 1,1,"CC");
    cov_label(! (P >= 1),2,"CC");
    if (! (P >= 1)) break;
    cov_label(P % 2 != 0,3,"CC");
    cov_label(! (P % 2 != 0),4,"CC");
    if (P % 2 != 0) {
      P --;
      S *= Y;
    }
    Y *= Y;
    P /= 2;
  }
  return S;
}

#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 20

int main () {
  HARNESS_START;
  int X;
  int N;
  
  _FLAT (X, "X", int);
  _FLAT (N, "N", int);
  
  (void) power (X, N);
  HARNESS_END;
  return 0;
}
      
