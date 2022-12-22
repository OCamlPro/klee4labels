#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

void swap(int *t, int i, int j)
{
  int tmp = *(t + i);
  cov_label(*(t + j) < 0,1,"WM ABS");
  *(t + i) = *(t + j);
  cov_label(tmp < 0,2,"WM ABS");
  *(t + j) = tmp;
  return;
}

void sort(int t[static 5], int n)
{
  int i;
  int j;
  int mi;
  int mv;
  ASSUME(n <= 5);
  cov_label((n < 0) != (n <= 0),3,"WM ROR");
  cov_label((n > 0) != (n <= 0),4,"WM ROR");
  cov_label((n >= 0) != (n <= 0),5,"WM ROR");
  cov_label(n < 0,6,"WM ABS");
  if (n <= 0) goto return_label;
  i = 0;
  while (1) {
    cov_label((i <= n - 1) != (i < n - 1),7,"WM ROR");
    cov_label((i > n - 1) != (i < n - 1),8,"WM ROR");
    cov_label((i >= n - 1) != (i < n - 1),9,"WM ROR");
    cov_label(i < 0,10,"WM ABS");
    cov_label(n * 1 != n - 1,11,"WM AOR");
    cov_label(n / 1 != n - 1,12,"WM AOR");
    cov_label(n + 1 != n - 1,13,"WM AOR");
    cov_label(n < 0,14,"WM ABS");
    if (! (i < n - 1)) break;
    cov_label(*(t + i) < 0,15,"WM ABS");
    mv = *(t + i);
    cov_label(i < 0,16,"WM ABS");
    mi = i;
    cov_label(i * 1 != i + 1,17,"WM AOR");
    cov_label(i / 1 != i + 1,18,"WM AOR");
    cov_label(i - 1 != i + 1,19,"WM AOR");
    cov_label(i < 0,20,"WM ABS");
    j = i + 1;
    while (1) {
      cov_label((j <= n) != (j < n),21,"WM ROR");
      cov_label((j > n) != (j < n),22,"WM ROR");
      cov_label((j >= n) != (j < n),23,"WM ROR");
      cov_label(j < 0,24,"WM ABS");
      cov_label(n < 0,25,"WM ABS");
      if (! (j < n)) break;
      cov_label((*(t + j) <= mv) != (*(t + j) < mv),26,"WM ROR");
      cov_label((*(t + j) > mv) != (*(t + j) < mv),27,"WM ROR");
      cov_label((*(t + j) >= mv) != (*(t + j) < mv),28,"WM ROR");
      cov_label(*(t + j) < 0,29,"WM ABS");
      cov_label(mv < 0,30,"WM ABS");
      if (*(t + j) < mv) {
        cov_label(j < 0,31,"WM ABS");
        mi = j;
        cov_label(*(t + j) < 0,32,"WM ABS");
        mv = *(t + j);
      }
      cov_label(j * 1 != j + 1,33,"WM AOR");
      cov_label(j / 1 != j + 1,34,"WM AOR");
      cov_label(j - 1 != j + 1,35,"WM AOR");
      cov_label(j < 0,36,"WM ABS");
      j ++;
    }
    swap((int *)t,i,mi);
    cov_label(i * 1 != i + 1,37,"WM AOR");
    cov_label(i / 1 != i + 1,38,"WM AOR");
    cov_label(i - 1 != i + 1,39,"WM AOR");
    cov_label(i < 0,40,"WM ABS");
    i ++;
  }
  return_label: return;
}

#define _MAX_PTR_ARRAY_LENGTH 5
#define _MAX_CSTRING_LENGTH 20

int main () {
  HARNESS_START;

  int t[5];
  int n;
  
  _FLAT (t, "t", int[5]);
  _FLAT (n, "n", int);
  
  (void) sort (t, n);
  HARNESS_END;
  return 0;
}
