#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int tritype(int i, int j, int k)
 {
   int type_code;
   cov_label(((i == 0 || j == 0) && k == 0) != ((i == 0 || j == 0) || k == 0),
            1,"WM COR");
   cov_label((i == 0 && j == 0) != (i == 0 || j == 0),2,"WM COR");
   cov_label((i != 0) != (i == 0),3,"WM ROR");
   cov_label(i < 0,4,"WM ABS");
   cov_label((j != 0) != (j == 0),5,"WM ROR");
   cov_label(j < 0,6,"WM ABS");
   cov_label((k != 0) != (k == 0),7,"WM ROR");
   cov_label(k < 0,8,"WM ABS");
   if ((i == 0 || j == 0) || k == 0) type_code = 4;
   else {
     type_code = 0;
     cov_label((i != j) != (i == j),9,"WM ROR");
     cov_label(i < 0,10,"WM ABS");
     cov_label(j < 0,11,"WM ABS");
     if (i == j) {
       cov_label(type_code * 1 != type_code + 1,12,"WM AOR");
       cov_label(type_code / 1 != type_code + 1,13,"WM AOR");
       cov_label(type_code - 1 != type_code + 1,14,"WM AOR");
       cov_label(type_code < 0,15,"WM ABS");
       type_code ++;
     }
     cov_label((i != k) != (i == k),16,"WM ROR");
     cov_label(i < 0,17,"WM ABS");
     cov_label(k < 0,18,"WM ABS");
     if (i == k) {
       cov_label(type_code * 2 != type_code + 2,19,"WM AOR");
       cov_label(type_code / 2 != type_code + 2,20,"WM AOR");
       cov_label(type_code - 2 != type_code + 2,21,"WM AOR");
       cov_label(type_code < 0,22,"WM ABS");
       type_code += 2;
     }
     cov_label((j != k) != (j == k),23,"WM ROR");
     cov_label(j < 0,24,"WM ABS");
     cov_label(k < 0,25,"WM ABS");
     if (j == k) {
       cov_label(type_code * 3 != type_code + 3,26,"WM AOR");
       cov_label(type_code / 3 != type_code + 3,27,"WM AOR");
       cov_label(type_code - 3 != type_code + 3,28,"WM AOR");
       cov_label(type_code < 0,29,"WM ABS");
       type_code += 3;
     }
     cov_label((type_code != 0) != (type_code == 0),30,"WM ROR");
     cov_label(type_code < 0,31,"WM ABS");
     if (type_code == 0) {
       cov_label(((i + j <= k || j + k <= i) && i + k <= j) != ((i + j <= k || 
                                                                j + k <= i) || 
                                                               i + k <= j),
                32,"WM COR");
       cov_label((i + j <= k && j + k <= i) != (i + j <= k || j + k <= i),33,
                "WM COR");
       cov_label((i + j < k) != (i + j <= k),34,"WM ROR");
       cov_label((i + j > k) != (i + j <= k),35,"WM ROR");
       cov_label((i + j >= k) != (i + j <= k),36,"WM ROR");
       cov_label(i * j != i + j,37,"WM AOR");
       cov_label(i / j != i + j,38,"WM AOR");
       cov_label(i - j != i + j,39,"WM AOR");
       cov_label(i < 0,40,"WM ABS");
       cov_label(j < 0,41,"WM ABS");
       cov_label(k < 0,42,"WM ABS");
       cov_label((j + k < i) != (j + k <= i),43,"WM ROR");
       cov_label((j + k > i) != (j + k <= i),44,"WM ROR");
       cov_label((j + k >= i) != (j + k <= i),45,"WM ROR");
       cov_label(j * k != j + k,46,"WM AOR");
       cov_label(j / k != j + k,47,"WM AOR");
       cov_label(j - k != j + k,48,"WM AOR");
       cov_label(j < 0,49,"WM ABS");
       cov_label(k < 0,50,"WM ABS");
       cov_label(i < 0,51,"WM ABS");
       cov_label((i + k < j) != (i + k <= j),52,"WM ROR");
       cov_label((i + k > j) != (i + k <= j),53,"WM ROR");
       cov_label((i + k >= j) != (i + k <= j),54,"WM ROR");
       cov_label(i * k != i + k,55,"WM AOR");
       cov_label(i / k != i + k,56,"WM AOR");
       cov_label(i - k != i + k,57,"WM AOR");
       cov_label(i < 0,58,"WM ABS");
       cov_label(k < 0,59,"WM ABS");
       cov_label(j < 0,60,"WM ABS");
       if ((i + j <= k || j + k <= i) || i + k <= j) type_code = 4;
       else type_code = 1;
     }
     else {
       cov_label((type_code < 3) != (type_code > 3),61,"WM ROR");
       cov_label((type_code <= 3) != (type_code > 3),62,"WM ROR");
       cov_label((type_code >= 3) != (type_code > 3),63,"WM ROR");
       cov_label(type_code < 0,64,"WM ABS");
       if (type_code > 3) type_code = 3;
       else {
         cov_label((type_code == 1 || i + j > k) != (type_code == 1 && 
                                                    i + j > k),65,"WM COR");
         cov_label((type_code != 1) != (type_code == 1),66,"WM ROR");
         cov_label(type_code < 0,67,"WM ABS");
         cov_label((i + j < k) != (i + j > k),68,"WM ROR");
         cov_label((i + j <= k) != (i + j > k),69,"WM ROR");
         cov_label((i + j >= k) != (i + j > k),70,"WM ROR");
         cov_label(i * j != i + j,71,"WM AOR");
         cov_label(i / j != i + j,72,"WM AOR");
         cov_label(i - j != i + j,73,"WM AOR");
         cov_label(i < 0,74,"WM ABS");
         cov_label(j < 0,75,"WM ABS");
         cov_label(k < 0,76,"WM ABS");
         if (type_code == 1 && i + j > k) type_code = 2;
         else {
           cov_label((type_code == 2 || i + k > j) != (type_code == 2 && 
                                                      i + k > j),77,"WM COR");
           cov_label((type_code != 2) != (type_code == 2),78,"WM ROR");
           cov_label(type_code < 0,79,"WM ABS");
           cov_label((i + k < j) != (i + k > j),80,"WM ROR");
           cov_label((i + k <= j) != (i + k > j),81,"WM ROR");
           cov_label((i + k >= j) != (i + k > j),82,"WM ROR");
           cov_label(i * k != i + k,83,"WM AOR");
           cov_label(i / k != i + k,84,"WM AOR");
           cov_label(i - k != i + k,85,"WM AOR");
           cov_label(i < 0,86,"WM ABS");
           cov_label(k < 0,87,"WM ABS");
           cov_label(j < 0,88,"WM ABS");
           if (type_code == 2 && i + k > j) type_code = 2;
           else {
             cov_label((type_code == 3 || j + k > i) != (type_code == 3 && 
                                                        j + k > i),89,
                      "WM COR");
             cov_label((type_code != 3) != (type_code == 3),90,"WM ROR");
             cov_label(type_code < 0,91,"WM ABS");
             cov_label((j + k < i) != (j + k > i),92,"WM ROR");
             cov_label((j + k <= i) != (j + k > i),93,"WM ROR");
             cov_label((j + k >= i) != (j + k > i),94,"WM ROR");
             cov_label(j * k != j + k,95,"WM AOR");
             cov_label(j / k != j + k,96,"WM AOR");
             cov_label(j - k != j + k,97,"WM AOR");
             cov_label(j < 0,98,"WM ABS");
             cov_label(k < 0,99,"WM ABS");
             cov_label(i < 0,100,"WM ABS");
             if (type_code == 3 && j + k > i) type_code = 2;
             else type_code = 4;
           }
         }
       }
     }
   }
   cov_label(type_code < 0,101,"WM ABS");
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
