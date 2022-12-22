#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int loopcnt;
int ap_isspace(char c)
{
  int __retres;
  cov_label((int)c == '\t',1,"CC");
  cov_label(! ((int)c == '\t'),2,"CC");
  cov_label((int)c == '\n',3,"CC");
  cov_label(! ((int)c == '\n'),4,"CC");
  cov_label((int)c == '\v',5,"CC");
  cov_label(! ((int)c == '\v'),6,"CC");
  cov_label((int)c == '\f',7,"CC");
  cov_label(! ((int)c == '\f'),8,"CC");
  cov_label((int)c == '\r',9,"CC");
  cov_label(! ((int)c == '\r'),10,"CC");
  cov_label((int)c == ' ',11,"CC");
  cov_label(! ((int)c == ' '),12,"CC");
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
  cov_label(dst_size == 0,13,"CC");
  cov_label(! (dst_size == 0),14,"CC");
  if (dst_size == 0) {
    __retres = dst;
    goto return_label;
  }
  i = 0;
  while (1) {
    cov_label(i < dst_size - 1,15,"CC");
    cov_label(! (i < dst_size - 1),16,"CC");
    if (! (i < dst_size - 1)) break;
    *(dst + i) = *(src + i);
    cov_label((int)*(src + i) == 0,17,"CC");
    cov_label(! ((int)*(src + i) == 0),18,"CC");
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
    cov_label(indice >= 100,19,"CC");
    cov_label(! (indice >= 100),20,"CC");
    if (! (indice >= 100)) {
      int tmp;
      tmp = indice;
      indice ++;
      c = *(nondetEntry + tmp);
      char tmp_2 = c;
    }
    tmp_0 = ap_isspace(c);
    cov_label(tmp_0,21,"CC");
    cov_label(! tmp_0,22,"CC");
    if (! tmp_0) break;
  }
  cov_label((int)c == '-',23,"CC");
  cov_label(! ((int)c == '-'),24,"CC");
  if ((int)c == '-') {
    cov_label(indice >= 100,25,"CC");
    cov_label(! (indice >= 100),26,"CC");
    if (! (indice >= 100)) {
      int tmp_1;
      tmp_1 = indice;
      indice ++;
      c = *(nondetEntry + tmp_1);
      char tmp_4 = c;
    }
    cov_label((int)c == '-',27,"CC");
    cov_label(! ((int)c == '-'),28,"CC");
    if ((int)c == '-') {
      while (1) {
        int tmp_3;
        cov_label(indice >= 100,29,"CC");
        cov_label(! (indice >= 100),30,"CC");
        if (! (indice >= 100)) {
          int tmp_2_0;
          tmp_2_0 = indice;
          indice ++;
          c = *(nondetEntry + tmp_2_0);
          char tmp_6 = c;
        }
        tmp_3 = ap_isspace(c);
        cov_label(tmp_3,31,"CC");
        cov_label(! tmp_3,32,"CC");
        if (! tmp_3) break;
      }
      cov_label((int)c == '>',33,"CC");
      cov_label(! ((int)c == '>'),34,"CC");
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
      cov_label(loopcnt >= 10,35,"CC");
      cov_label(! (loopcnt >= 10),36,"CC");
      if (loopcnt >= 10) {
        __retres = (char *)0;
        goto return_label;
      }
      cov_label(t == tagbuf_len,37,"CC");
      cov_label(! (t == tagbuf_len),38,"CC");
      if (t == tagbuf_len) {
        *(tag + t) = (char)0;
        __retres = (char *)0;
        goto return_label;
      }
      cov_label((int)c == '=',39,"CC");
      cov_label(! ((int)c == '='),40,"CC");
      if ((int)c == '=') goto _LOR;
      else {
        int tmp_4_0;
        tmp_4_0 = ap_isspace(c);
        cov_label(tmp_4_0,41,"CC");
        cov_label(! tmp_4_0,42,"CC");
        if (tmp_4_0) _LOR: break;
      }
      tmp_5 = ap_tolower(c);
      *(tag + t) = (char)tmp_5;
      t ++;
      cov_label(indice >= 100,43,"CC");
      cov_label(! (indice >= 100),44,"CC");
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
    cov_label(tmp_8_0,45,"CC");
    cov_label(! tmp_8_0,46,"CC");
    if (! tmp_8_0) break;
    cov_label(indice >= 100,47,"CC");
    cov_label(! (indice >= 100),48,"CC");
    if (! (indice >= 100)) {
      int tmp_7;
      tmp_7 = indice;
      indice ++;
      c = *(nondetEntry + tmp_7);
      char tmp_10 = c;
    }
  }
  cov_label((int)c != '=',49,"CC");
  cov_label(! ((int)c != '='),50,"CC");
  if ((int)c != '=') {
    __retres = (char *)0;
    goto return_label;
  }
  while (1) {
    int tmp_10_0;
    cov_label(indice >= 100,51,"CC");
    cov_label(! (indice >= 100),52,"CC");
    if (! (indice >= 100)) {
      int tmp_9;
      tmp_9 = indice;
      indice ++;
      c = *(nondetEntry + tmp_9);
      char tmp_12 = c;
    }
    tmp_10_0 = ap_isspace(c);
    cov_label(tmp_10_0,53,"CC");
    cov_label(! tmp_10_0,54,"CC");
    if (! tmp_10_0) break;
  }
  cov_label((int)c != '\"',55,"CC");
  cov_label(! ((int)c != '\"'),56,"CC");
  cov_label((int)c != '\'',57,"CC");
  cov_label(! ((int)c != '\''),58,"CC");
  if ((int)c != '\"' && (int)c != '\'') {
    __retres = (char *)0;
    goto return_label;
  }
  term = c;
  while (1) {
    loopcnt ++;
    cov_label(loopcnt >= 10,59,"CC");
    cov_label(! (loopcnt >= 10),60,"CC");
    if (loopcnt >= 10) {
      __retres = (char *)0;
      goto return_label;
    }
    cov_label(indice >= 100,61,"CC");
    cov_label(! (indice >= 100),62,"CC");
    if (! (indice >= 100)) {
      int tmp_11;
      tmp_11 = indice;
      indice ++;
      c = *(nondetEntry + tmp_11);
      char tmp_14 = c;
    }
    cov_label(t == tagbuf_len,63,"CC");
    cov_label(! (t == tagbuf_len),64,"CC");
    if (t == tagbuf_len) {
      *(tag + t) = (char)0;
      __retres = (char *)0;
      goto return_label;
    }
    cov_label((int)c == '\\',65,"CC");
    cov_label(! ((int)c == '\\'),66,"CC");
    if ((int)c == '\\') {
      *(tag + t) = c;
      t ++;
      cov_label(indice >= 100,67,"CC");
      cov_label(! (indice >= 100),68,"CC");
      if (! (indice >= 100)) {
        int tmp_12_0;
        tmp_12_0 = indice;
        indice ++;
        c = *(nondetEntry + tmp_12_0);
        char tmp_16 = c;
      }
    }
    else {
      cov_label((int)c == (int)term,69,"CC");
      cov_label(! ((int)c == (int)term),70,"CC");
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
      
