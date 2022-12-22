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
  cov_label(cual < 0,1,"WM ABS");
  ccual = cual;
  cov_label((cual != 1) != (cual == 1),2,"WM ROR");
  cov_label(cual < 0,3,"WM ABS");
  if (cual == 1) {
    cov_label(mA * mB != mA / mB,4,"WM AOR");
    cov_label(mA + mB != mA / mB,5,"WM AOR");
    cov_label(mA - mB != mA / mB,6,"WM AOR");
    cov_label(mA < 0,7,"WM ABS");
    cov_label(mB < 0,8,"WM ABS");
    r[0] = mA / mB;
    cov_label(mA * mC != mA / mC,9,"WM AOR");
    cov_label(mA + mC != mA / mC,10,"WM AOR");
    cov_label(mA - mC != mA / mC,11,"WM AOR");
    cov_label(mA < 0,12,"WM ABS");
    cov_label(mC < 0,13,"WM ABS");
    r[1] = mA / mC;
    cov_label(mA * mD != mA / mD,14,"WM AOR");
    cov_label(mA + mD != mA / mD,15,"WM AOR");
    cov_label(mA - mD != mA / mD,16,"WM AOR");
    cov_label(mA < 0,17,"WM ABS");
    cov_label(mD < 0,18,"WM ABS");
    r[2] = mA / mD;
  }
  else {
    cov_label((cual != 2) != (cual == 2),19,"WM ROR");
    cov_label(cual < 0,20,"WM ABS");
    if (cual == 2) {
      cov_label(mB * mA != mB / mA,21,"WM AOR");
      cov_label(mB + mA != mB / mA,22,"WM AOR");
      cov_label(mB - mA != mB / mA,23,"WM AOR");
      cov_label(mB < 0,24,"WM ABS");
      cov_label(mA < 0,25,"WM ABS");
      r[0] = mB / mA;
      cov_label(mB * mC != mB / mC,26,"WM AOR");
      cov_label(mB + mC != mB / mC,27,"WM AOR");
      cov_label(mB - mC != mB / mC,28,"WM AOR");
      cov_label(mB < 0,29,"WM ABS");
      cov_label(mC < 0,30,"WM ABS");
      r[1] = mB / mC;
      cov_label(mB * mD != mB / mD,31,"WM AOR");
      cov_label(mB + mD != mB / mD,32,"WM AOR");
      cov_label(mB - mD != mB / mD,33,"WM AOR");
      cov_label(mB < 0,34,"WM ABS");
      cov_label(mD < 0,35,"WM ABS");
      r[2] = mB / mD;
    }
    else {
      cov_label((cual != 3) != (cual == 3),36,"WM ROR");
      cov_label(cual < 0,37,"WM ABS");
      if (cual == 3) {
        cov_label(mC * mA != mC / mA,38,"WM AOR");
        cov_label(mC + mA != mC / mA,39,"WM AOR");
        cov_label(mC - mA != mC / mA,40,"WM AOR");
        cov_label(mC < 0,41,"WM ABS");
        cov_label(mA < 0,42,"WM ABS");
        r[0] = mC / mA;
        cov_label(mC * mB != mC / mB,43,"WM AOR");
        cov_label(mC + mB != mC / mB,44,"WM AOR");
        cov_label(mC - mB != mC / mB,45,"WM AOR");
        cov_label(mC < 0,46,"WM ABS");
        cov_label(mB < 0,47,"WM ABS");
        r[1] = mC / mB;
        cov_label(mC * mD != mC / mD,48,"WM AOR");
        cov_label(mC + mD != mC / mD,49,"WM AOR");
        cov_label(mC - mD != mC / mD,50,"WM AOR");
        cov_label(mC < 0,51,"WM ABS");
        cov_label(mD < 0,52,"WM ABS");
        r[2] = mC / mD;
      }
      else {
        cov_label(mD * mA != mD / mA,53,"WM AOR");
        cov_label(mD + mA != mD / mA,54,"WM AOR");
        cov_label(mD - mA != mD / mA,55,"WM AOR");
        cov_label(mD < 0,56,"WM ABS");
        cov_label(mA < 0,57,"WM ABS");
        r[0] = mD / mA;
        cov_label(mD * mB != mD / mB,58,"WM AOR");
        cov_label(mD + mB != mD / mB,59,"WM AOR");
        cov_label(mD - mB != mD / mB,60,"WM AOR");
        cov_label(mD < 0,61,"WM ABS");
        cov_label(mB < 0,62,"WM ABS");
        r[1] = mD / mB;
        cov_label(mD * mC != mD / mC,63,"WM AOR");
        cov_label(mD + mC != mD / mC,64,"WM AOR");
        cov_label(mD - mC != mD / mC,65,"WM AOR");
        cov_label(mD < 0,66,"WM ABS");
        cov_label(mC < 0,67,"WM ABS");
        r[2] = mD / mC;
      }
    }
  }
  __retres = 0;
  cov_label(__retres < 0,68,"WM ABS");
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
