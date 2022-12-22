#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

void swap(int *t, int i, int j)
{
  int tmp = *(t + i);
  *(t + i) = *(t + j);
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
  cov_label(n <= 0,1,"CC");
  cov_label(! (n <= 0),2,"CC");
  if (n <= 0) goto return_label;
  i = 0;
  while (1) {
    cov_label(i < n - 1,3,"CC");
    cov_label(! (i < n - 1),4,"CC");
    if (! (i < n - 1)) break;
    mv = *(t + i);
    mi = i;
    j = i + 1;
    while (1) {
      cov_label(j < n,5,"CC");
      cov_label(! (j < n),6,"CC");
      if (! (j < n)) break;
      cov_label(*(t + j) < mv,7,"CC");
      cov_label(! (*(t + j) < mv),8,"CC");
      if (*(t + j) < mv) {
        mi = j;
        mv = *(t + j);
      }
      j ++;
    }
    swap((int *)t,i,mi);
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
      
