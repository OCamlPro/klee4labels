#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int loopcnt;
int ap_isspace(char c)
{
  int __retres;
  cov_label((((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || 
             (int)c == '\f') || (int)c == '\r') || (int)c == ' ',1,"DC");
  cov_label(! ((((((int)c == '\t' || (int)c == '\n') || (int)c == '\v') || 
                (int)c == '\f') || (int)c == '\r') || (int)c == ' '),2,"DC");
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
  cov_label(dst_size == 0,3,"DC");
  cov_label(! (dst_size == 0),4,"DC");
  if (dst_size == 0) {
    __retres = dst;
    goto return_label;
  }
  i = 0;
  while (1) {
    cov_label(i < dst_size - 1,5,"DC");
    cov_label(! (i < dst_size - 1),6,"DC");
    if (! (i < dst_size - 1)) break;
    *(dst + i) = *(src + i);
    cov_label((int)*(src + i) == 0,7,"DC");
    cov_label(! ((int)*(src + i) == 0),8,"DC");
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
    cov_label(indice >= 100,9,"DC");
    cov_label(! (indice >= 100),10,"DC");
    if (! (indice >= 100)) {
      int tmp;
      tmp = indice;
      indice ++;
      c = *(nondetEntry + tmp);
      char tmp_2 = c;
    }
    tmp_0 = ap_isspace(c);
    cov_label(tmp_0,11,"DC");
    cov_label(! tmp_0,12,"DC");
    if (! tmp_0) break;
  }
  cov_label((int)c == '-',13,"DC");
  cov_label(! ((int)c == '-'),14,"DC");
  if ((int)c == '-') {
    cov_label(indice >= 100,15,"DC");
    cov_label(! (indice >= 100),16,"DC");
    if (! (indice >= 100)) {
      int tmp_1;
      tmp_1 = indice;
      indice ++;
      c = *(nondetEntry + tmp_1);
      char tmp_4 = c;
    }
    cov_label((int)c == '-',17,"DC");
    cov_label(! ((int)c == '-'),18,"DC");
    if ((int)c == '-') {
      while (1) {
        int tmp_3;
        cov_label(indice >= 100,19,"DC");
        cov_label(! (indice >= 100),20,"DC");
        if (! (indice >= 100)) {
          int tmp_2_0;
          tmp_2_0 = indice;
          indice ++;
          c = *(nondetEntry + tmp_2_0);
          char tmp_6 = c;
        }
        tmp_3 = ap_isspace(c);
        cov_label(tmp_3,21,"DC");
        cov_label(! tmp_3,22,"DC");
        if (! tmp_3) break;
      }
      cov_label((int)c == '>',23,"DC");
      cov_label(! ((int)c == '>'),24,"DC");
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
      cov_label(loopcnt >= 10,25,"DC");
      cov_label(! (loopcnt >= 10),26,"DC");
      if (loopcnt >= 10) {
        __retres = (char *)0;
        goto return_label;
      }
      cov_label(t == tagbuf_len,27,"DC");
      cov_label(! (t == tagbuf_len),28,"DC");
      if (t == tagbuf_len) {
        *(tag + t) = (char)0;
        __retres = (char *)0;
        goto return_label;
      }
      cov_label((int)c == '=',29,"DC");
      cov_label(! ((int)c == '='),30,"DC");
      if ((int)c == '=') goto _LOR;
      else {
        int tmp_4_0;
        tmp_4_0 = ap_isspace(c);
        cov_label(tmp_4_0,31,"DC");
        cov_label(! tmp_4_0,32,"DC");
        if (tmp_4_0) _LOR: break;
      }
      tmp_5 = ap_tolower(c);
      *(tag + t) = (char)tmp_5;
      t ++;
      cov_label(indice >= 100,33,"DC");
      cov_label(! (indice >= 100),34,"DC");
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
    cov_label(tmp_8_0,35,"DC");
    cov_label(! tmp_8_0,36,"DC");
    if (! tmp_8_0) break;
    cov_label(indice >= 100,37,"DC");
    cov_label(! (indice >= 100),38,"DC");
    if (! (indice >= 100)) {
      int tmp_7;
      tmp_7 = indice;
      indice ++;
      c = *(nondetEntry + tmp_7);
      char tmp_10 = c;
    }
  }
  cov_label((int)c != '=',39,"DC");
  cov_label(! ((int)c != '='),40,"DC");
  if ((int)c != '=') {
    __retres = (char *)0;
    goto return_label;
  }
  while (1) {
    int tmp_10_0;
    cov_label(indice >= 100,41,"DC");
    cov_label(! (indice >= 100),42,"DC");
    if (! (indice >= 100)) {
      int tmp_9;
      tmp_9 = indice;
      indice ++;
      c = *(nondetEntry + tmp_9);
      char tmp_12 = c;
    }
    tmp_10_0 = ap_isspace(c);
    cov_label(tmp_10_0,43,"DC");
    cov_label(! tmp_10_0,44,"DC");
    if (! tmp_10_0) break;
  }
  cov_label((int)c != '\"' && (int)c != '\'',45,"DC");
  cov_label(! ((int)c != '\"' && (int)c != '\''),46,"DC");
  if ((int)c != '\"' && (int)c != '\'') {
    __retres = (char *)0;
    goto return_label;
  }
  term = c;
  while (1) {
    loopcnt ++;
    cov_label(loopcnt >= 10,47,"DC");
    cov_label(! (loopcnt >= 10),48,"DC");
    if (loopcnt >= 10) {
      __retres = (char *)0;
      goto return_label;
    }
    cov_label(indice >= 100,49,"DC");
    cov_label(! (indice >= 100),50,"DC");
    if (! (indice >= 100)) {
      int tmp_11;
      tmp_11 = indice;
      indice ++;
      c = *(nondetEntry + tmp_11);
      char tmp_14 = c;
    }
    cov_label(t == tagbuf_len,51,"DC");
    cov_label(! (t == tagbuf_len),52,"DC");
    if (t == tagbuf_len) {
      *(tag + t) = (char)0;
      __retres = (char *)0;
      goto return_label;
    }
    cov_label((int)c == '\\',53,"DC");
    cov_label(! ((int)c == '\\'),54,"DC");
    if ((int)c == '\\') {
      *(tag + t) = c;
      t ++;
      cov_label(indice >= 100,55,"DC");
      cov_label(! (indice >= 100),56,"DC");
      if (! (indice >= 100)) {
        int tmp_12_0;
        tmp_12_0 = indice;
        indice ++;
        c = *(nondetEntry + tmp_12_0);
        char tmp_16 = c;
      }
    }
    else {
      cov_label((int)c == (int)term,57,"DC");
      cov_label(! ((int)c == (int)term),58,"DC");
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
      
