
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
    cov_label((P < 1) != (P >= 1),1,"WM ROR");
    cov_label((P <= 1) != (P >= 1),2,"WM ROR");
    cov_label((P > 1) != (P >= 1),3,"WM ROR");
    cov_label(P < 0,4,"WM ABS");
    if (! (P >= 1)) break;
    cov_label((P % 2 == 0) != (P % 2 != 0),5,"WM ROR");
    cov_label(P < 0,6,"WM ABS");
    if (P % 2 != 0) {
      cov_label(P * 1 != P - 1,7,"WM AOR");
      cov_label(P / 1 != P - 1,8,"WM AOR");
      cov_label(P + 1 != P - 1,9,"WM AOR");
      cov_label(P < 0,10,"WM ABS");
      P --;
      cov_label(S / Y != S * Y,11,"WM AOR");
      cov_label(S + Y != S * Y,12,"WM AOR");
      cov_label(S - Y != S * Y,13,"WM AOR");
      cov_label(S < 0,14,"WM ABS");
      cov_label(Y < 0,15,"WM ABS");
      S *= Y;
    }
    cov_label(Y / Y != Y * Y,16,"WM AOR");
    cov_label(Y + Y != Y * Y,17,"WM AOR");
    cov_label(Y - Y != Y * Y,18,"WM AOR");
    cov_label(Y < 0,19,"WM ABS");
    cov_label(Y < 0,20,"WM ABS");
    Y *= Y;
    cov_label(P * 2 != P / 2,21,"WM AOR");
    cov_label(P + 2 != P / 2,22,"WM AOR");
    cov_label(P - 2 != P / 2,23,"WM AOR");
    cov_label(P < 0,24,"WM ABS");
    P /= 2;
  }
  cov_label(S < 0,25,"WM ABS");
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
      
