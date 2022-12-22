#include "errno.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int mA;
int mB;
int mC;
int mD;
int ccual;
int relativeWeight(int cual)
{
  int __retres;
  int r[3];
  ASSUME((((mA > 0 && mB > 0) && mC > 0) && mD > 0) != 0);
  ccual = cual;
  cov_label(cual == 1,1,"CC");
  cov_label(! (cual == 1),2,"CC");
  if (cual == 1) {
    r[0] = mA / mB;
    r[1] = mA / mC;
    r[2] = mA / mD;
  }
  else {
    cov_label(cual == 2,3,"CC");
    cov_label(! (cual == 2),4,"CC");
    if (cual == 2) {
      r[0] = mB / mA;
      r[1] = mB / mC;
      r[2] = mB / mD;
    }
    else {
      cov_label(cual == 3,5,"CC");
      cov_label(! (cual == 3),6,"CC");
      if (cual == 3) {
        r[0] = mC / mA;
        r[1] = mC / mB;
        r[2] = mC / mD;
      }
      else {
        r[0] = mD / mA;
        r[1] = mD / mB;
        r[2] = mD / mC;
      }
    }
  }
  __retres = 0;
  return __retres;
}


int main () {
  int cual;
  
  _FLAT (cual, "cual", int);
  _FLAT (ccual, "ccual", int);
  _FLAT (mD, "mD", int);
  _FLAT (mC, "mC", int);
  _FLAT (mB, "mB", int);
  _FLAT (mA, "mA", int);
  
  (void) relativeWeight (cual);
  HARNESS_END;
  return 0;
}
