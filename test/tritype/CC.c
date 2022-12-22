#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int tritype(int i, int j, int k)
 {
   int type_code;
   cov_label(i == 0,1,"CC");
   cov_label(! (i == 0),2,"CC");
   cov_label(j == 0,3,"CC");
   cov_label(! (j == 0),4,"CC");
   cov_label(k == 0,5,"CC");
   cov_label(! (k == 0),6,"CC");
   if ((i == 0 || j == 0) || k == 0) type_code = 4;
   else {
     type_code = 0;
     cov_label(i == j,7,"CC");
     cov_label(! (i == j),8,"CC");
     if (i == j) type_code ++;
     cov_label(i == k,9,"CC");
     cov_label(! (i == k),10,"CC");
     if (i == k) type_code += 2;
     cov_label(j == k,11,"CC");
     cov_label(! (j == k),12,"CC");
     if (j == k) type_code += 3;
     cov_label(type_code == 0,13,"CC");
     cov_label(! (type_code == 0),14,"CC");
     if (type_code == 0) {
       cov_label(i + j <= k,15,"CC");
       cov_label(! (i + j <= k),16,"CC");
       cov_label(j + k <= i,17,"CC");
       cov_label(! (j + k <= i),18,"CC");
       cov_label(i + k <= j,19,"CC");
       cov_label(! (i + k <= j),20,"CC");
       if ((i + j <= k || j + k <= i) || i + k <= j) type_code = 4;
       else type_code = 1;
     }
     else {
       cov_label(type_code > 3,21,"CC");
       cov_label(! (type_code > 3),22,"CC");
       if (type_code > 3) type_code = 3;
       else {
         cov_label(type_code == 1,23,"CC");
         cov_label(! (type_code == 1),24,"CC");
         cov_label(i + j > k,25,"CC");
         cov_label(! (i + j > k),26,"CC");
         if (type_code == 1 && i + j > k) type_code = 2;
         else {
           cov_label(type_code == 2,27,"CC");
           cov_label(! (type_code == 2),28,"CC");
           cov_label(i + k > j,29,"CC");
           cov_label(! (i + k > j),30,"CC");
           if (type_code == 2 && i + k > j) type_code = 2;
           else {
             cov_label(type_code == 3,31,"CC");
             cov_label(! (type_code == 3),32,"CC");
             cov_label(j + k > i,33,"CC");
             cov_label(! (j + k > i),34,"CC");
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
