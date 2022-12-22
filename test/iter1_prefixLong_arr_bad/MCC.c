#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int loopcnt;
int ap_isspace(char c)
{
  int __retres;
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                             (int)c == 13 && 
                                                             (int)c == 32)))),
           1,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                             (int)c == 13 && ! (
                                                             (int)c == 32))))),
           2,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                             ! ((int)c == 13) && 
                                                             (int)c == 32)))),
           3,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                             ! ((int)c == 13) && ! (
                                                             (int)c == 32))))),
           4,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                             (int)c == 13 && 
                                                             (int)c == 32)))),
           5,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                             (int)c == 13 && ! (
                                                             (int)c == 32))))),
           6,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                             ! ((int)c == 13) && 
                                                             (int)c == 32)))),
           7,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                             ! ((int)c == 13) && ! (
                                                             (int)c == 32))))),
           8,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && ((int)c == 12 && (
                                                                 (int)c == 13 && 
                                                                 (int)c == 32)))),
           9,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && ((int)c == 12 && (
                                                                 (int)c == 13 && ! (
                                                                 (int)c == 32))))),
           10,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && ((int)c == 12 && (
                                                                 ! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           11,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && ((int)c == 12 && (
                                                                 ! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           12,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && (! ((int)c == 12) && (
                                                                 (int)c == 13 && 
                                                                 (int)c == 32)))),
           13,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && (! ((int)c == 12) && (
                                                                 (int)c == 13 && ! (
                                                                 (int)c == 32))))),
           14,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && (! ((int)c == 12) && (
                                                                 ! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           15,"MCC");
  cov_label((int)c == 9 && ((int)c == 10 && (! ((int)c == 11) && (! ((int)c == 12) && (
                                                                 ! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           16,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && ((int)c == 12 && (
                                                                 (int)c == 13 && 
                                                                 (int)c == 32)))),
           17,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && ((int)c == 12 && (
                                                                 (int)c == 13 && ! (
                                                                 (int)c == 32))))),
           18,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && ((int)c == 12 && (
                                                                 ! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           19,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && ((int)c == 12 && (
                                                                 ! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           20,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 (int)c == 13 && 
                                                                 (int)c == 32)))),
           21,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 (int)c == 13 && ! (
                                                                 (int)c == 32))))),
           22,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 ! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           23,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 ! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           24,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                (int)c == 12 && ((int)c == 13 && 
                                                                 (int)c == 32)))),
           25,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                (int)c == 12 && ((int)c == 13 && ! (
                                                                 (int)c == 32))))),
           26,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                (int)c == 12 && (! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           27,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                (int)c == 12 && (! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           28,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                (int)c == 13 && (int)c == 32)))),
           29,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                (int)c == 13 && ! ((int)c == 32))))),
           30,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                ! ((int)c == 13) && (int)c == 32)))),
           31,"MCC");
  cov_label((int)c == 9 && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                ! ((int)c == 13) && ! (
                                                (int)c == 32))))),32,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                                 (int)c == 13 && 
                                                                 (int)c == 32)))),
           33,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                                 (int)c == 13 && ! (
                                                                 (int)c == 32))))),
           34,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                                 ! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           35,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && ((int)c == 12 && (
                                                                 ! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           36,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 (int)c == 13 && 
                                                                 (int)c == 32)))),
           37,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 (int)c == 13 && ! (
                                                                 (int)c == 32))))),
           38,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 ! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           39,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && ((int)c == 11 && (! ((int)c == 12) && (
                                                                 ! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           40,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                (int)c == 12 && ((int)c == 13 && 
                                                                 (int)c == 32)))),
           41,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                (int)c == 12 && ((int)c == 13 && ! (
                                                                 (int)c == 32))))),
           42,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                (int)c == 12 && (! ((int)c == 13) && 
                                                                 (int)c == 32)))),
           43,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                (int)c == 12 && (! ((int)c == 13) && ! (
                                                                 (int)c == 32))))),
           44,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                (int)c == 13 && (int)c == 32)))),
           45,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                (int)c == 13 && ! ((int)c == 32))))),
           46,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                ! ((int)c == 13) && (int)c == 32)))),
           47,"MCC");
  cov_label(! ((int)c == 9) && ((int)c == 10 && (! ((int)c == 11) && (
                                                ! ((int)c == 12) && (
                                                ! ((int)c == 13) && ! (
                                                (int)c == 32))))),48,"MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    (int)c == 12 && (
                                                    (int)c == 13 && (int)c == 32)))),
           49,"MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    (int)c == 12 && (
                                                    (int)c == 13 && ! (
                                                    (int)c == 32))))),50,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    (int)c == 12 && (
                                                    ! ((int)c == 13) && 
                                                    (int)c == 32)))),51,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    (int)c == 12 && (
                                                    ! ((int)c == 13) && ! (
                                                    (int)c == 32))))),52,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    ! ((int)c == 12) && (
                                                    (int)c == 13 && (int)c == 32)))),
           53,"MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    ! ((int)c == 12) && (
                                                    (int)c == 13 && ! (
                                                    (int)c == 32))))),54,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    ! ((int)c == 12) && (
                                                    ! ((int)c == 13) && 
                                                    (int)c == 32)))),55,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && ((int)c == 11 && (
                                                    ! ((int)c == 12) && (
                                                    ! ((int)c == 13) && ! (
                                                    (int)c == 32))))),56,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    (int)c == 12 && (
                                                    (int)c == 13 && (int)c == 32)))),
           57,"MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    (int)c == 12 && (
                                                    (int)c == 13 && ! (
                                                    (int)c == 32))))),58,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    (int)c == 12 && (
                                                    ! ((int)c == 13) && 
                                                    (int)c == 32)))),59,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    (int)c == 12 && (
                                                    ! ((int)c == 13) && ! (
                                                    (int)c == 32))))),60,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    ! ((int)c == 12) && (
                                                    (int)c == 13 && (int)c == 32)))),
           61,"MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    ! ((int)c == 12) && (
                                                    (int)c == 13 && ! (
                                                    (int)c == 32))))),62,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    ! ((int)c == 12) && (
                                                    ! ((int)c == 13) && 
                                                    (int)c == 32)))),63,
           "MCC");
  cov_label(! ((int)c == 9) && (! ((int)c == 10) && (! ((int)c == 11) && (
                                                    ! ((int)c == 12) && (
                                                    ! ((int)c == 13) && ! (
                                                    (int)c == 32))))),64,
           "MCC");
  if ((((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || (int)c == '\f') || 
       (int)c == '\r') || (int)c == ' ') {
    __retres = 1;
    goto return_label;
  }
  __retres = 0;
  return_label: return __retres;
}

int ap_tolower(char c)
{
  int __retres;
  __retres = (int)c;
  return __retres;
}

char *ap_cpystrn(char *dst, char const *src, int dst_size)
{
  char *__retres;
  int i;
  cov_label(dst_size == 0,65,"MCC");
  cov_label(! (dst_size == 0),66,"MCC");
  if (dst_size == 0) {
    __retres = dst;
    goto return_label;
  }
  i = 0;
  while (1) {
    cov_label(i < dst_size - 1,67,"MCC");
    cov_label(! (i < dst_size - 1),68,"MCC");
    if (! (i < dst_size - 1)) break;
    *(dst + i) = *(src + i);
    cov_label((int)*(src + i) == 0,69,"MCC");
    cov_label(! ((int)*(src + i) == 0),70,"MCC");
    if ((int)*(src + i) == 0) {
      __retres = dst + i;
      goto return_label;
    }
    i ++;
  }
  *(dst + i) = (char)0;
  __retres = dst + i;
  return_label: return __retres;
}

char *get_tag(char *tag, int tagbuf_len, char *nondetEntry)
{
  char *__retres;
  char *tag_val;
  char c;
  char term;
  int t;
  ASSUME(tagbuf_len > 0);
  ASSUME(tagbuf_len <= 10);
  int indice = 0;
  loopcnt = 0;
  t = 0;
  tagbuf_len --;
  while (1) {
    int tmp_0;
    cov_label(indice >= 100,71,"MCC");
    cov_label(! (indice >= 100),72,"MCC");
    if (! (indice >= 100)) {
      int tmp;
      tmp = indice;
      indice ++;
      c = *(nondetEntry + tmp);
      char tmp_2 = c;
    }
    tmp_0 = ap_isspace(c);
    cov_label(tmp_0,73,"MCC");
    cov_label(! tmp_0,74,"MCC");
    if (! tmp_0) break;
  }
  cov_label((int)c == '-',75,"MCC");
  cov_label(! ((int)c == '-'),76,"MCC");
  if ((int)c == '-') {
    cov_label(indice >= 100,77,"MCC");
    cov_label(! (indice >= 100),78,"MCC");
    if (! (indice >= 100)) {
      int tmp_1;
      tmp_1 = indice;
      indice ++;
      c = *(nondetEntry + tmp_1);
      char tmp_4 = c;
    }
    cov_label((int)c == '-',79,"MCC");
    cov_label(! ((int)c == '-'),80,"MCC");
    if ((int)c == '-') {
      while (1) {
        int tmp_3;
        cov_label(indice >= 100,81,"MCC");
        cov_label(! (indice >= 100),82,"MCC");
        if (! (indice >= 100)) {
          int tmp_2_0;
          tmp_2_0 = indice;
          indice ++;
          c = *(nondetEntry + tmp_2_0);
          char tmp_6 = c;
        }
        tmp_3 = ap_isspace(c);
        cov_label(tmp_3,83,"MCC");
        cov_label(! tmp_3,84,"MCC");
        if (! tmp_3) break;
      }
      cov_label((int)c == '>',85,"MCC");
      cov_label(! ((int)c == '>'),86,"MCC");
      if ((int)c == '>') {
        ap_cpystrn(tag,"done",tagbuf_len);
        __retres = tag;
        goto return_label;
      }
    }
    __retres = (char *)0;
    goto return_label;
  }
  while (1) {
    {
      int tmp_5;
      loopcnt ++;
      cov_label(loopcnt >= 10,87,"MCC");
      cov_label(! (loopcnt >= 10),88,"MCC");
      if (loopcnt >= 10) {
        __retres = (char *)0;
        goto return_label;
      }
      cov_label(t == tagbuf_len,89,"MCC");
      cov_label(! (t == tagbuf_len),90,"MCC");
      if (t == tagbuf_len) {
        *(tag + t) = (char)0;
        __retres = (char *)0;
        goto return_label;
      }
      cov_label((int)c == '=',91,"MCC");
      cov_label(! ((int)c == '='),92,"MCC");
      if ((int)c == '=') goto _LOR;
      else {
        int tmp_4_0;
        tmp_4_0 = ap_isspace(c);
        cov_label(tmp_4_0,93,"MCC");
        cov_label(! tmp_4_0,94,"MCC");
        if (tmp_4_0) _LOR: break;
      }
      tmp_5 = ap_tolower(c);
      *(tag + t) = (char)tmp_5;
      t ++;
      cov_label(indice >= 100,95,"MCC");
      cov_label(! (indice >= 100),96,"MCC");
      if (! (indice >= 100)) {
        int tmp_6_0;
        tmp_6_0 = indice;
        indice ++;
        c = *(nondetEntry + tmp_6_0);
        char tmp_8 = c;
      }
    }
  }
  *(tag + t) = (char)0;
  t ++;
  tag_val = tag + t;
  while (1) {
    int tmp_8_0;
    tmp_8_0 = ap_isspace(c);
    cov_label(tmp_8_0,97,"MCC");
    cov_label(! tmp_8_0,98,"MCC");
    if (! tmp_8_0) break;
    cov_label(indice >= 100,99,"MCC");
    cov_label(! (indice >= 100),100,"MCC");
    if (! (indice >= 100)) {
      int tmp_7;
      tmp_7 = indice;
      indice ++;
      c = *(nondetEntry + tmp_7);
      char tmp_10 = c;
    }
  }
  cov_label((int)c != '=',101,"MCC");
  cov_label(! ((int)c != '='),102,"MCC");
  if ((int)c != '=') {
    __retres = (char *)0;
    goto return_label;
  }
  while (1) {
    int tmp_10_0;
    cov_label(indice >= 100,103,"MCC");
    cov_label(! (indice >= 100),104,"MCC");
    if (! (indice >= 100)) {
      int tmp_9;
      tmp_9 = indice;
      indice ++;
      c = *(nondetEntry + tmp_9);
      char tmp_12 = c;
    }
    tmp_10_0 = ap_isspace(c);
    cov_label(tmp_10_0,105,"MCC");
    cov_label(! tmp_10_0,106,"MCC");
    if (! tmp_10_0) break;
  }
  cov_label((int)c != 34 && (int)c != 39,107,"MCC");
  cov_label((int)c != 34 && ! ((int)c != 39),108,"MCC");
  cov_label(! ((int)c != 34) && (int)c != 39,109,"MCC");
  cov_label(! ((int)c != 34) && ! ((int)c != 39),110,"MCC");
  if ((int)c != '\"' && (int)c != '\'') {
    __retres = (char *)0;
    goto return_label;
  }
  term = c;
  while (1) {
    loopcnt ++;
    cov_label(loopcnt >= 10,111,"MCC");
    cov_label(! (loopcnt >= 10),112,"MCC");
    if (loopcnt >= 10) {
      __retres = (char *)0;
      goto return_label;
    }
    cov_label(indice >= 100,113,"MCC");
    cov_label(! (indice >= 100),114,"MCC");
    if (! (indice >= 100)) {
      int tmp_11;
      tmp_11 = indice;
      indice ++;
      c = *(nondetEntry + tmp_11);
      char tmp_14 = c;
    }
    cov_label(t == tagbuf_len,115,"MCC");
    cov_label(! (t == tagbuf_len),116,"MCC");
    if (t == tagbuf_len) {
      *(tag + t) = (char)0;
      __retres = (char *)0;
      goto return_label;
    }
    cov_label((int)c == '\\',117,"MCC");
    cov_label(! ((int)c == '\\'),118,"MCC");
    if ((int)c == '\\') {
      *(tag + t) = c;
      t ++;
      cov_label(indice >= 100,119,"MCC");
      cov_label(! (indice >= 100),120,"MCC");
      if (! (indice >= 100)) {
        int tmp_12_0;
        tmp_12_0 = indice;
        indice ++;
        c = *(nondetEntry + tmp_12_0);
        char tmp_16 = c;
      }
    }
    else {
      cov_label((int)c == (int)term,121,"MCC");
      cov_label(! ((int)c == (int)term),122,"MCC");
      if ((int)c == (int)term) break;
    }
    *(tag + t) = c;
    t ++;
  }
  *(tag + t) = (char)0;
  __retres = tag;
  return_label: return __retres;
}

#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 5
static char _CSTRING_SYMBOL (v0)[6]; /* tag */
static char _CSTRING_SYMBOL (v1)[6]; /* nondetEntry */

int main () {

  HARNESS_START;

  int tagbuf_len;
  char (* tag);
  char (* nondetEntry);
  
  _FLAT (tagbuf_len, "tagbuf_len", int);
  _FLAT (loopcnt, "loopcnt", int);
  _CSTRING_DECL (v0, "tag");
  _CSTRING_DECL (v1, "nondetEntry");
  _CSTRING_FILL (v0, "tag");
  _CSTRING_FILL (v1, "nondetEntry");
  tag = _CSTRING (v0);
  nondetEntry = _CSTRING (v1);
  
  (void) get_tag (tag, tagbuf_len, nondetEntry);

  HARNESS_END;

  return 0;
}
      
