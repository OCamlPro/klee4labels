#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int tritype(int i, int j, int k)
 {
   int type_code;
   cov_label((i == 0 || j == 0) || k == 0,1,"DC");
   cov_label(! ((i == 0 || j == 0) || k == 0),2,"DC");
   if ((i == 0 || j == 0) || k == 0) type_code = 4;
   else {
     type_code = 0;
     cov_label(i == j,3,"DC");
     cov_label(! (i == j),4,"DC");
     if (i == j) type_code ++;
     cov_label(i == k,5,"DC");
     cov_label(! (i == k),6,"DC");
     if (i == k) type_code += 2;
     cov_label(j == k,7,"DC");
     cov_label(! (j == k),8,"DC");
     if (j == k) type_code += 3;
     cov_label(type_code == 0,9,"DC");
     cov_label(! (type_code == 0),10,"DC");
     if (type_code == 0) {
       cov_label((i + j <= k || j + k <= i) || i + k <= j,11,"DC");
       cov_label(! ((i + j <= k || j + k <= i) || i + k <= j),12,"DC");
       if ((i + j <= k || j + k <= i) || i + k <= j) type_code = 4;
       else type_code = 1;
     }
     else {
       cov_label(type_code > 3,13,"DC");
       cov_label(! (type_code > 3),14,"DC");
       if (type_code > 3) type_code = 3;
       else {
         cov_label(type_code == 1 && i + j > k,15,"DC");
         cov_label(! (type_code == 1 && i + j > k),16,"DC");
         if (type_code == 1 && i + j > k) type_code = 2;
         else {
           cov_label(type_code == 2 && i + k > j,17,"DC");
           cov_label(! (type_code == 2 && i + k > j),18,"DC");
           if (type_code == 2 && i + k > j) type_code = 2;
           else {
             cov_label(type_code == 3 && j + k > i,19,"DC");
             cov_label(! (type_code == 3 && j + k > i),20,"DC");
             if (type_code == 3 && j + k > i) type_code = 2;
             else type_code = 4;
           }
         }
       }
     }
   }
   return type_code;
 }

int main () {
  HARNESS_START;

  int i;
  int j;
  int k;
  
  _FLAT (i, "i", int);
  _FLAT (j, "j", int);
  _FLAT (k, "k", int);
  
  (void) tritype (i, j, k);
  HARNESS_END;
  return 0;
}
