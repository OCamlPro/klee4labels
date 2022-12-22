#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int loopcnt;
int ap_isspace(char c)
{
  int __retres;
  cov_label(((((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || 
              (int)c == '\f') || (int)c == '\r') && (int)c == ' ') != (
           (((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || 
             (int)c == '\f') || (int)c == '\r') || (int)c == ' '),1,"WM COR");
  cov_label((((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || 
             (int)c == '\f') && (int)c == '\r') != (((((int)c == '\t' || 
                                                       (int)c == '\n') || 
                                                      (int)c == '\v') || 
                                                     (int)c == '\f') || 
                                                    (int)c == '\r'),2,
           "WM COR");
  cov_label(((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') && 
            (int)c == '\f') != ((((int)c == '\t' || (int)c == '\n') || 
                                 (int)c == '\v') || (int)c == '\f'),3,
           "WM COR");
  cov_label((((int)c == '\t' || (int)c == '\n') && (int)c == '\v') != (
           ((int)c == '\t' || (int)c == '\n') || (int)c == '\v'),4,"WM COR");
  cov_label(((int)c == '\t' && (int)c == '\n') != ((int)c == '\t' || (int)c == '\n'),
           5,"WM COR");
  cov_label(((int)c != '\t') != ((int)c == '\t'),6,"WM ROR");
  cov_label(((int)c != '\n') != ((int)c == '\n'),7,"WM ROR");
  cov_label(((int)c != '\v') != ((int)c == '\v'),8,"WM ROR");
  cov_label(((int)c != '\f') != ((int)c == '\f'),9,"WM ROR");
  cov_label(((int)c != '\r') != ((int)c == '\r'),10,"WM ROR");
  cov_label(((int)c != ' ') != ((int)c == ' '),11,"WM ROR");
  if ((((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || (int)c == '\f') || 
       (int)c == '\r') || (int)c == ' ') {
    __retres = 1;
    goto return_label;
  }
  __retres = 0;
  return_label: {
                  cov_label(__retres < 0,12,"WM ABS");
                  return __retres;
                }
}

int ap_tolower(char c)
{
  int __retres;
  __retres = (int)c;
  cov_label(__retres < 0,13,"WM ABS");
  return __retres;
}

char *ap_cpystrn(char *dst, char const *src, int dst_size)
{
  char *__retres;
  int i;
  cov_label((dst_size != 0) != (dst_size == 0),14,"WM ROR");
  cov_label(dst_size < 0,15,"WM ABS");
  if (dst_size == 0) {
    cov_label(dst < 0,16,"WM ABS");
    __retres = dst;
    goto return_label;
  }
  i = 0;
  while (1) {
    cov_label((i <= dst_size - 1) != (i < dst_size - 1),17,"WM ROR");
    cov_label((i > dst_size - 1) != (i < dst_size - 1),18,"WM ROR");
    cov_label((i >= dst_size - 1) != (i < dst_size - 1),19,"WM ROR");
    cov_label(i < 0,20,"WM ABS");
    cov_label(dst_size * 1 != dst_size - 1,21,"WM AOR");
    cov_label(dst_size / 1 != dst_size - 1,22,"WM AOR");
    cov_label(dst_size + 1 != dst_size - 1,23,"WM AOR");
    cov_label(dst_size < 0,24,"WM ABS");
    if (! (i < dst_size - 1)) break;
    cov_label(*(src + i) < 0,25,"WM ABS");
    *(dst + i) = *(src + i);
    cov_label(((int)*(src + i) != 0) != ((int)*(src + i) == 0),26,"WM ROR");
    if ((int)*(src + i) == 0) {
      cov_label(dst < 0,27,"WM ABS");
      cov_label(i < 0,28,"WM ABS");
      __retres = dst + i;
      goto return_label;
    }
    cov_label(i * 1 != i + 1,29,"WM AOR");
    cov_label(i / 1 != i + 1,30,"WM AOR");
    cov_label(i - 1 != i + 1,31,"WM AOR");
    cov_label(i < 0,32,"WM ABS");
    i ++;
  }
  *(dst + i) = (char)0;
  cov_label(dst < 0,33,"WM ABS");
  cov_label(i < 0,34,"WM ABS");
  __retres = dst + i;
  return_label: {
                  cov_label(__retres < 0,35,"WM ABS");
                  return __retres;
                }
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
  cov_label(tagbuf_len * 1 != tagbuf_len - 1,36,"WM AOR");
  cov_label(tagbuf_len / 1 != tagbuf_len - 1,37,"WM AOR");
  cov_label(tagbuf_len + 1 != tagbuf_len - 1,38,"WM AOR");
  cov_label(tagbuf_len < 0,39,"WM ABS");
  tagbuf_len --;
  while (1) {
    int tmp_0;
    cov_label((indice < 100) != (indice >= 100),40,"WM ROR");
    cov_label((indice <= 100) != (indice >= 100),41,"WM ROR");
    cov_label((indice > 100) != (indice >= 100),42,"WM ROR");
    cov_label(indice < 0,43,"WM ABS");
    if (! (indice >= 100)) {
      int tmp;
      cov_label(indice < 0,44,"WM ABS");
      tmp = indice;
      cov_label(indice * 1 != indice + 1,45,"WM AOR");
      cov_label(indice / 1 != indice + 1,46,"WM AOR");
      cov_label(indice - 1 != indice + 1,47,"WM AOR");
      cov_label(indice < 0,48,"WM ABS");
      indice ++;
      cov_label(*(nondetEntry + tmp) < 0,49,"WM ABS");
      c = *(nondetEntry + tmp);
      char tmp_2 = c;
    }
    tmp_0 = ap_isspace(c);
    cov_label(tmp_0 < 0,50,"WM ABS");
    if (! tmp_0) break;
  }
  cov_label(((int)c != '-') != ((int)c == '-'),51,"WM ROR");
  if ((int)c == '-') {
    cov_label((indice < 100) != (indice >= 100),52,"WM ROR");
    cov_label((indice <= 100) != (indice >= 100),53,"WM ROR");
    cov_label((indice > 100) != (indice >= 100),54,"WM ROR");
    cov_label(indice < 0,55,"WM ABS");
    if (! (indice >= 100)) {
      int tmp_1;
      cov_label(indice < 0,56,"WM ABS");
      tmp_1 = indice;
      cov_label(indice * 1 != indice + 1,57,"WM AOR");
      cov_label(indice / 1 != indice + 1,58,"WM AOR");
      cov_label(indice - 1 != indice + 1,59,"WM AOR");
      cov_label(indice < 0,60,"WM ABS");
      indice ++;
      cov_label(*(nondetEntry + tmp_1) < 0,61,"WM ABS");
      c = *(nondetEntry + tmp_1);
      char tmp_4 = c;
    }
    cov_label(((int)c != '-') != ((int)c == '-'),62,"WM ROR");
    if ((int)c == '-') {
      while (1) {
        int tmp_3;
        cov_label((indice < 100) != (indice >= 100),63,"WM ROR");
        cov_label((indice <= 100) != (indice >= 100),64,"WM ROR");
        cov_label((indice > 100) != (indice >= 100),65,"WM ROR");
        cov_label(indice < 0,66,"WM ABS");
        if (! (indice >= 100)) {
          int tmp_2_0;
          cov_label(indice < 0,67,"WM ABS");
          tmp_2_0 = indice;
          cov_label(indice * 1 != indice + 1,68,"WM AOR");
          cov_label(indice / 1 != indice + 1,69,"WM AOR");
          cov_label(indice - 1 != indice + 1,70,"WM AOR");
          cov_label(indice < 0,71,"WM ABS");
          indice ++;
          cov_label(*(nondetEntry + tmp_2_0) < 0,72,"WM ABS");
          c = *(nondetEntry + tmp_2_0);
          char tmp_6 = c;
        }
        tmp_3 = ap_isspace(c);
        cov_label(tmp_3 < 0,73,"WM ABS");
        if (! tmp_3) break;
      }
      cov_label(((int)c != '>') != ((int)c == '>'),74,"WM ROR");
      if ((int)c == '>') {
        ap_cpystrn(tag,"done",tagbuf_len);
        cov_label(tag < 0,75,"WM ABS");
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
      cov_label(loopcnt * 1 != loopcnt + 1,76,"WM AOR");
      cov_label(loopcnt / 1 != loopcnt + 1,77,"WM AOR");
      cov_label(loopcnt - 1 != loopcnt + 1,78,"WM AOR");
      cov_label(loopcnt < 0,79,"WM ABS");
      loopcnt ++;
      cov_label((loopcnt < 10) != (loopcnt >= 10),80,"WM ROR");
      cov_label((loopcnt <= 10) != (loopcnt >= 10),81,"WM ROR");
      cov_label((loopcnt > 10) != (loopcnt >= 10),82,"WM ROR");
      cov_label(loopcnt < 0,83,"WM ABS");
      if (loopcnt >= 10) {
        __retres = (char *)0;
        goto return_label;
      }
      cov_label((t != tagbuf_len) != (t == tagbuf_len),84,"WM ROR");
      cov_label(t < 0,85,"WM ABS");
      cov_label(tagbuf_len < 0,86,"WM ABS");
      if (t == tagbuf_len) {
        *(tag + t) = (char)0;
        __retres = (char *)0;
        goto return_label;
      }
      cov_label(((int)c != '=') != ((int)c == '='),87,"WM ROR");
      if ((int)c == '=') goto _LOR;
      else {
        int tmp_4_0;
        tmp_4_0 = ap_isspace(c);
        cov_label(tmp_4_0 < 0,88,"WM ABS");
        if (tmp_4_0) _LOR: break;
      }
      tmp_5 = ap_tolower(c);
      *(tag + t) = (char)tmp_5;
      cov_label(t * 1 != t + 1,89,"WM AOR");
      cov_label(t / 1 != t + 1,90,"WM AOR");
      cov_label(t - 1 != t + 1,91,"WM AOR");
      cov_label(t < 0,92,"WM ABS");
      t ++;
      cov_label((indice < 100) != (indice >= 100),93,"WM ROR");
      cov_label((indice <= 100) != (indice >= 100),94,"WM ROR");
      cov_label((indice > 100) != (indice >= 100),95,"WM ROR");
      cov_label(indice < 0,96,"WM ABS");
      if (! (indice >= 100)) {
        int tmp_6_0;
        cov_label(indice < 0,97,"WM ABS");
        tmp_6_0 = indice;
        cov_label(indice * 1 != indice + 1,98,"WM AOR");
        cov_label(indice / 1 != indice + 1,99,"WM AOR");
        cov_label(indice - 1 != indice + 1,100,"WM AOR");
        cov_label(indice < 0,101,"WM ABS");
        indice ++;
        cov_label(*(nondetEntry + tmp_6_0) < 0,102,"WM ABS");
        c = *(nondetEntry + tmp_6_0);
        char tmp_8 = c;
      }
    }
  }
  *(tag + t) = (char)0;
  cov_label(t * 1 != t + 1,103,"WM AOR");
  cov_label(t / 1 != t + 1,104,"WM AOR");
  cov_label(t - 1 != t + 1,105,"WM AOR");
  cov_label(t < 0,106,"WM ABS");
  t ++;
  cov_label(tag < 0,107,"WM ABS");
  cov_label(t < 0,108,"WM ABS");
  tag_val = tag + t;
  while (1) {
    int tmp_8_0;
    tmp_8_0 = ap_isspace(c);
    cov_label(tmp_8_0 < 0,109,"WM ABS");
    if (! tmp_8_0) break;
    cov_label((indice < 100) != (indice >= 100),110,"WM ROR");
    cov_label((indice <= 100) != (indice >= 100),111,"WM ROR");
    cov_label((indice > 100) != (indice >= 100),112,"WM ROR");
    cov_label(indice < 0,113,"WM ABS");
    if (! (indice >= 100)) {
      int tmp_7;
      cov_label(indice < 0,114,"WM ABS");
      tmp_7 = indice;
      cov_label(indice * 1 != indice + 1,115,"WM AOR");
      cov_label(indice / 1 != indice + 1,116,"WM AOR");
      cov_label(indice - 1 != indice + 1,117,"WM AOR");
      cov_label(indice < 0,118,"WM ABS");
      indice ++;
      cov_label(*(nondetEntry + tmp_7) < 0,119,"WM ABS");
      c = *(nondetEntry + tmp_7);
      char tmp_10 = c;
    }
  }
  cov_label(((int)c == '=') != ((int)c != '='),120,"WM ROR");
  if ((int)c != '=') {
    __retres = (char *)0;
    goto return_label;
  }
  while (1) {
    int tmp_10_0;
    cov_label((indice < 100) != (indice >= 100),121,"WM ROR");
    cov_label((indice <= 100) != (indice >= 100),122,"WM ROR");
    cov_label((indice > 100) != (indice >= 100),123,"WM ROR");
    cov_label(indice < 0,124,"WM ABS");
    if (! (indice >= 100)) {
      int tmp_9;
      cov_label(indice < 0,125,"WM ABS");
      tmp_9 = indice;
      cov_label(indice * 1 != indice + 1,126,"WM AOR");
      cov_label(indice / 1 != indice + 1,127,"WM AOR");
      cov_label(indice - 1 != indice + 1,128,"WM AOR");
      cov_label(indice < 0,129,"WM ABS");
      indice ++;
      cov_label(*(nondetEntry + tmp_9) < 0,130,"WM ABS");
      c = *(nondetEntry + tmp_9);
      char tmp_12 = c;
    }
    tmp_10_0 = ap_isspace(c);
    cov_label(tmp_10_0 < 0,131,"WM ABS");
    if (! tmp_10_0) break;
  }
  cov_label(((int)c != '\"' || (int)c != '\'') != ((int)c != '\"' && (int)c != '\''),
           132,"WM COR");
  cov_label(((int)c == '\"') != ((int)c != '\"'),133,"WM ROR");
  cov_label(((int)c == '\'') != ((int)c != '\''),134,"WM ROR");
  if ((int)c != '\"' && (int)c != '\'') {
    __retres = (char *)0;
    goto return_label;
  }
  cov_label(c < 0,135,"WM ABS");
  term = c;
  while (1) {
    cov_label(loopcnt * 1 != loopcnt + 1,136,"WM AOR");
    cov_label(loopcnt / 1 != loopcnt + 1,137,"WM AOR");
    cov_label(loopcnt - 1 != loopcnt + 1,138,"WM AOR");
    cov_label(loopcnt < 0,139,"WM ABS");
    loopcnt ++;
    cov_label((loopcnt < 10) != (loopcnt >= 10),140,"WM ROR");
    cov_label((loopcnt <= 10) != (loopcnt >= 10),141,"WM ROR");
    cov_label((loopcnt > 10) != (loopcnt >= 10),142,"WM ROR");
    cov_label(loopcnt < 0,143,"WM ABS");
    if (loopcnt >= 10) {
      __retres = (char *)0;
      goto return_label;
    }
    cov_label((indice < 100) != (indice >= 100),144,"WM ROR");
    cov_label((indice <= 100) != (indice >= 100),145,"WM ROR");
    cov_label((indice > 100) != (indice >= 100),146,"WM ROR");
    cov_label(indice < 0,147,"WM ABS");
    if (! (indice >= 100)) {
      int tmp_11;
      cov_label(indice < 0,148,"WM ABS");
      tmp_11 = indice;
      cov_label(indice * 1 != indice + 1,149,"WM AOR");
      cov_label(indice / 1 != indice + 1,150,"WM AOR");
      cov_label(indice - 1 != indice + 1,151,"WM AOR");
      cov_label(indice < 0,152,"WM ABS");
      indice ++;
      cov_label(*(nondetEntry + tmp_11) < 0,153,"WM ABS");
      c = *(nondetEntry + tmp_11);
      char tmp_14 = c;
    }
    cov_label((t != tagbuf_len) != (t == tagbuf_len),154,"WM ROR");
    cov_label(t < 0,155,"WM ABS");
    cov_label(tagbuf_len < 0,156,"WM ABS");
    if (t == tagbuf_len) {
      *(tag + t) = (char)0;
      __retres = (char *)0;
      goto return_label;
    }
    cov_label(((int)c != '\\') != ((int)c == '\\'),157,"WM ROR");
    if ((int)c == '\\') {
      cov_label(c < 0,158,"WM ABS");
      *(tag + t) = c;
      cov_label(t * 1 != t + 1,159,"WM AOR");
      cov_label(t / 1 != t + 1,160,"WM AOR");
      cov_label(t - 1 != t + 1,161,"WM AOR");
      cov_label(t < 0,162,"WM ABS");
      t ++;
      cov_label((indice < 100) != (indice >= 100),163,"WM ROR");
      cov_label((indice <= 100) != (indice >= 100),164,"WM ROR");
      cov_label((indice > 100) != (indice >= 100),165,"WM ROR");
      cov_label(indice < 0,166,"WM ABS");
      if (! (indice >= 100)) {
        int tmp_12_0;
        cov_label(indice < 0,167,"WM ABS");
        tmp_12_0 = indice;
        cov_label(indice * 1 != indice + 1,168,"WM AOR");
        cov_label(indice / 1 != indice + 1,169,"WM AOR");
        cov_label(indice - 1 != indice + 1,170,"WM AOR");
        cov_label(indice < 0,171,"WM ABS");
        indice ++;
        cov_label(*(nondetEntry + tmp_12_0) < 0,172,"WM ABS");
        c = *(nondetEntry + tmp_12_0);
        char tmp_16 = c;
      }
    }
    else {
      cov_label(((int)c != (int)term) != ((int)c == (int)term),173,"WM ROR");
      if ((int)c == (int)term) break;
    }
    cov_label(c < 0,174,"WM ABS");
    *(tag + t) = c;
    cov_label(t * 1 != t + 1,175,"WM AOR");
    cov_label(t / 1 != t + 1,176,"WM AOR");
    cov_label(t - 1 != t + 1,177,"WM AOR");
    cov_label(t < 0,178,"WM ABS");
    t ++;
  }
  *(tag + t) = (char)0;
  cov_label(tag < 0,179,"WM ABS");
  __retres = tag;
  return_label: {
                  cov_label(__retres < 0,180,"WM ABS");
                  return __retres;
                }
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
