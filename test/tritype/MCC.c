#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int tritype(int i, int j, int k)
 {
   int type_code;
   cov_label(i == 0 && (j == 0 && k == 0),1,"MCC");
   cov_label(i == 0 && (j == 0 && ! (k == 0)),2,"MCC");
   cov_label(i == 0 && (! (j == 0) && k == 0),3,"MCC");
   cov_label(i == 0 && (! (j == 0) && ! (k == 0)),4,"MCC");
   cov_label(! (i == 0) && (j == 0 && k == 0),5,"MCC");
   cov_label(! (i == 0) && (j == 0 && ! (k == 0)),6,"MCC");
   cov_label(! (i == 0) && (! (j == 0) && k == 0),7,"MCC");
   cov_label(! (i == 0) && (! (j == 0) && ! (k == 0)),8,"MCC");
   if ((i == 0 || j == 0) || k == 0) type_code = 4;
   else {
     type_code = 0;
     cov_label(i == j,9,"MCC");
     cov_label(! (i == j),10,"MCC");
     if (i == j) type_code ++;
     cov_label(i == k,11,"MCC");
     cov_label(! (i == k),12,"MCC");
     if (i == k) type_code += 2;
     cov_label(j == k,13,"MCC");
     cov_label(! (j == k),14,"MCC");
     if (j == k) type_code += 3;
     cov_label(type_code == 0,15,"MCC");
     cov_label(! (type_code == 0),16,"MCC");
     if (type_code == 0) {
       cov_label(i + j <= k && (j + k <= i && i + k <= j),17,"MCC");
       cov_label(i + j <= k && (j + k <= i && ! (i + k <= j)),18,"MCC");
       cov_label(i + j <= k && (! (j + k <= i) && i + k <= j),19,"MCC");
       cov_label(i + j <= k && (! (j + k <= i) && ! (i + k <= j)),20,"MCC");
       cov_label(! (i + j <= k) && (j + k <= i && i + k <= j),21,"MCC");
       cov_label(! (i + j <= k) && (j + k <= i && ! (i + k <= j)),22,"MCC");
       cov_label(! (i + j <= k) && (! (j + k <= i) && i + k <= j),23,"MCC");
       cov_label(! (i + j <= k) && (! (j + k <= i) && ! (i + k <= j)),24,
                "MCC");
       if ((i + j <= k || j + k <= i) || i + k <= j) type_code = 4;
       else type_code = 1;
     }
     else {
       cov_label(type_code > 3,25,"MCC");
       cov_label(! (type_code > 3),26,"MCC");
       if (type_code > 3) type_code = 3;
       else {
         cov_label(type_code == 1 && i + j > k,27,"MCC");
         cov_label(type_code == 1 && ! (i + j > k),28,"MCC");
         cov_label(! (type_code == 1) && i + j > k,29,"MCC");
         cov_label(! (type_code == 1) && ! (i + j > k),30,"MCC");
         if (type_code == 1 && i + j > k) type_code = 2;
         else {
           cov_label(type_code == 2 && i + k > j,31,"MCC");
           cov_label(type_code == 2 && ! (i + k > j),32,"MCC");
           cov_label(! (type_code == 2) && i + k > j,33,"MCC");
           cov_label(! (type_code == 2) && ! (i + k > j),34,"MCC");
           if (type_code == 2 && i + k > j) type_code = 2;
           else {
             cov_label(type_code == 3 && j + k > i,35,"MCC");
             cov_label(type_code == 3 && ! (j + k > i),36,"MCC");
             cov_label(! (type_code == 3) && j + k > i,37,"MCC");
             cov_label(! (type_code == 3) && ! (j + k > i),38,"MCC");
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
