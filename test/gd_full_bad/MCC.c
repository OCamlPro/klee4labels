#include "errno.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int my_strcmp(char const *s1, char const *s2)
 {
   int __retres;
   cov_label(s1 == s2,1,"MCC");
   cov_label(! (s1 == s2),2,"MCC");
   if (s1 == s2) {
     __retres = 0;
     goto return_label;
   }
   while (1) {
     char const *tmp_0;
     char const *tmp;
     tmp_0 = s2;
     s2 ++;
     ;
     cov_label((int)*s1 == (int)*tmp_0,3,"MCC");
     cov_label(! ((int)*s1 == (int)*tmp_0),4,"MCC");
     if (! ((int)*s1 == (int)*tmp_0)) break;
     tmp = s1;
     s1 ++;
     ;
     cov_label((int)*tmp == '\000',5,"MCC");
     cov_label(! ((int)*tmp == '\000'),6,"MCC");
     if ((int)*tmp == '\000') {
       __retres = 0;
       goto return_label;
     }
   }
   s2 --;
   ;
   __retres = (int)*((unsigned char *)s1) - (int)*((unsigned char *)s2);
   return_label: return __retres;
 }

int search(char *keyName, char **base, int nmemb)
{
  int __retres;
  int iter;
  __retres = 1;
  return __retres;
}

void gdImageStringFTEx(char *string, int nondetEntry)
{
  int next;
  int encoding;
  int i;
  int ch;
  int len;
  int byte;
  encoding = nondetEntry;
  cov_label(encoding > 2 && encoding < 0,7,"MCC");
  cov_label(encoding > 2 && ! (encoding < 0),8,"MCC");
  cov_label(! (encoding > 2) && encoding < 0,9,"MCC");
  cov_label(! (encoding > 2) && ! (encoding < 0),10,"MCC");
  if (encoding > 2 || encoding < 0) goto return_label;
  next = 0;
  i = 0;
  while (1) {
    cov_label((int)*(string + next) != 0,11,"MCC");
    cov_label(! ((int)*(string + next) != 0),12,"MCC");
    if (! ((int)*(string + next) != 0)) break;
    ch = (int)*(string + next);
    cov_label(ch == '\r',13,"MCC");
    cov_label(! (ch == '\r'),14,"MCC");
    if (ch == '\r') {
      next ++;
      goto __Cont;
    }
    cov_label(ch == '\n',15,"MCC");
    cov_label(! (ch == '\n'),16,"MCC");
    if (ch == '\n') {
      next ++;
      goto __Cont;
    }
    switch (encoding) {
      case 0:
      {
        char *p;
        char entity_name_buf[8 + 1];
        char *key;
        int ii;
        int indiceP = 0;
        int n = 0;
        int res = 0;
        char *entities[3] =
          {(char *)"AElig", (char *)"Aacute", (char *)"Acirc"};
        byte = (int)((unsigned char)*(string + next));
        cov_label(byte == '&',17,"MCC");
        cov_label(! (byte == '&'),18,"MCC");
        if (byte == '&') {
          byte = (int)((unsigned char)*(string + (next + 1)));
          cov_label(byte == '#',19,"MCC");
          cov_label(! (byte == '#'),20,"MCC");
          if (byte == '#') {
            byte = (int)((unsigned char)*(string + (next + 2)));
            cov_label(byte == 120 && byte == 88,21,"MCC");
            cov_label(byte == 120 && ! (byte == 88),22,"MCC");
            cov_label(! (byte == 120) && byte == 88,23,"MCC");
            cov_label(! (byte == 120) && ! (byte == 88),24,"MCC");
            if (byte == 'x' || byte == 'X') {
              ii = 3;
              while (1) {
                cov_label(ii < 8,25,"MCC");
                cov_label(! (ii < 8),26,"MCC");
                if (! (ii < 8)) break;
                byte = (int)((unsigned char)*(string + (next + ii)));
                cov_label(byte >= 65 && byte <= 70,27,"MCC");
                cov_label(byte >= 65 && ! (byte <= 70),28,"MCC");
                cov_label(! (byte >= 65) && byte <= 70,29,"MCC");
                cov_label(! (byte >= 65) && ! (byte <= 70),30,"MCC");
                if (byte >= 'A' && byte <= 'F') byte = (byte - 'A') + 10;
                else {
                  cov_label(byte >= 97 && byte <= 102,31,"MCC");
                  cov_label(byte >= 97 && ! (byte <= 102),32,"MCC");
                  cov_label(! (byte >= 97) && byte <= 102,33,"MCC");
                  cov_label(! (byte >= 97) && ! (byte <= 102),34,"MCC");
                  if (byte >= 'a' && byte <= 'f') byte = (byte - 'a') + 10;
                  else {
                    cov_label(byte >= 48 && byte <= 57,35,"MCC");
                    cov_label(byte >= 48 && ! (byte <= 57),36,"MCC");
                    cov_label(! (byte >= 48) && byte <= 57,37,"MCC");
                    cov_label(! (byte >= 48) && ! (byte <= 57),38,"MCC");
                    if (byte >= '0' && byte <= '9') byte -= '0'; else 
                                                                   break;
                  }
                }
                n = n * 16 + byte;
                ii ++;
              }
            }
            else {
              ii = 2;
              while (1) {
                cov_label(ii < 8,39,"MCC");
                cov_label(! (ii < 8),40,"MCC");
                if (! (ii < 8)) break;
                byte = (int)((unsigned char)*(string + (next + ii)));
                cov_label(byte >= 48 && byte <= 57,41,"MCC");
                cov_label(byte >= 48 && ! (byte <= 57),42,"MCC");
                cov_label(! (byte >= 48) && byte <= 57,43,"MCC");
                cov_label(! (byte >= 48) && ! (byte <= 57),44,"MCC");
                if (byte >= '0' && byte <= '9') n = n * 10 + (byte - '0');
                else break;
                ii ++;
              }
            }
            cov_label(byte == ';',45,"MCC");
            cov_label(! (byte == ';'),46,"MCC");
            if (byte == ';') {
              ii ++;
              len = ii;
              goto endFun;
            }
          }
          else {
            p = entity_name_buf;
            key = p;
            ii = 1;
            while (1) {
              cov_label(ii < 1 + 8,47,"MCC");
              cov_label(! (ii < 1 + 8),48,"MCC");
              if (! (ii < 1 + 8)) break;
              byte = (int)((unsigned char)*(string + (next + ii)));
              cov_label(byte == 0,49,"MCC");
              cov_label(! (byte == 0),50,"MCC");
              if (byte == 0) break;
              cov_label(byte == ';',51,"MCC");
              cov_label(! (byte == ';'),52,"MCC");
              if (byte == ';') {
                *(p + indiceP) = (char)0;
                indiceP ++;
                res = search(key,entities,3);
                cov_label(res != 0,53,"MCC");
                cov_label(! (res != 0),54,"MCC");
                if (res != 0) {
                  ii ++;
                  len = ii;
                  goto endFun;
                }
                break;
              }
              *(p + indiceP) = (char)byte;
              indiceP ++;
              ii ++;
            }
          }
        }
        len = 1;
        byte = (int)((unsigned char)*(string + next));
        cov_label(byte < 0xC0,55,"MCC");
        cov_label(! (byte < 0xC0),56,"MCC");
        if (byte < 0xC0) len = 1;
        else {
          cov_label(byte < 0xE0,57,"MCC");
          cov_label(! (byte < 0xE0),58,"MCC");
          if (byte < 0xE0) {
            cov_label(((int)*(string + (next + 1)) & 0xC0) == 0x80,59,"MCC");
            cov_label(! (((int)*(string + (next + 1)) & 0xC0) == 0x80),60,
                     "MCC");
            if (((int)*(string + (next + 1)) & 0xC0) == 0x80) len = 2;
            len = 1;
          }
          else {
            cov_label(byte < 0xF0,61,"MCC");
            cov_label(! (byte < 0xF0),62,"MCC");
            if (byte < 0xF0) {
              cov_label(((int)*(string + (next + 1)) & 0xC0) == 0x80 && 
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80,63,"MCC");
              cov_label(((int)*(string + (next + 1)) & 0xC0) == 0x80 && ! (
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80),64,
                       "MCC");
              cov_label(! (((int)*(string + (next + 1)) & 0xC0) == 0x80) && 
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80,65,"MCC");
              cov_label(! (((int)*(string + (next + 1)) & 0xC0) == 0x80) && ! (
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80),66,
                       "MCC");
              if (((int)*(string + (next + 1)) & 0xC0) == 0x80 && ((int)*(
                                                                   string + (
                                                                   next + 2)) & 0xC0) == 0x80) 
                len = 3;
              len = 1;
            }
          }
        }
        endFun: next += len;
      }
      break;
      case 1:
      {
        unsigned char c;
        c = (unsigned char)*(string + next);
        cov_label(0xA1 <= (int)c && (int)c <= 0xFE,67,"MCC");
        cov_label(0xA1 <= (int)c && ! ((int)c <= 0xFE),68,"MCC");
        cov_label(! (0xA1 <= (int)c) && (int)c <= 0xFE,69,"MCC");
        cov_label(! (0xA1 <= (int)c) && ! ((int)c <= 0xFE),70,"MCC");
        if (0xA1 <= (int)c && (int)c <= 0xFE) next ++;
        cov_label((int)*(string + next) != 0,71,"MCC");
        cov_label(! ((int)*(string + next) != 0),72,"MCC");
        if ((int)*(string + next) != 0) next ++;
      }
      break;
      case 2:
      {
        ch = (int)*(string + next) & 0xFF;
        next ++;
        cov_label(ch >= 161 && (int)*(string + next) != 0,73,"MCC");
        cov_label(ch >= 161 && ! ((int)*(string + next) != 0),74,"MCC");
        cov_label(! (ch >= 161) && (int)*(string + next) != 0,75,"MCC");
        cov_label(! (ch >= 161) && ! ((int)*(string + next) != 0),76,"MCC");
        if (ch >= 161 && (int)*(string + next) != 0) next ++;
      }
      break;
    }
    __Cont: i ++;
  }
  return_label: return;
}


#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 10
static char _CSTRING_SYMBOL (v0)[11]; /* string */

int main () {
  HARNESS_START;
  int nondetEntry;
  char (* string);
  
  _FLAT (nondetEntry, "nondetEntry", int);
  _CSTRING_DECL (v0, "string");
  _CSTRING_FILL (v0, "string");
  string = _CSTRING (v0);
  
  (void) gdImageStringFTEx (string, nondetEntry);
  HARNESS_END;
  return 0;
}
