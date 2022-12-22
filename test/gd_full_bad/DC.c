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
   cov_label(s1 == s2,1,"DC");
   cov_label(! (s1 == s2),2,"DC");
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
     cov_label((int)*s1 == (int)*tmp_0,3,"DC");
     cov_label(! ((int)*s1 == (int)*tmp_0),4,"DC");
     if (! ((int)*s1 == (int)*tmp_0)) break;
     tmp = s1;
     s1 ++;
     ;
     cov_label((int)*tmp == '\000',5,"DC");
     cov_label(! ((int)*tmp == '\000'),6,"DC");
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
  cov_label(encoding > 2 || encoding < 0,7,"DC");
  cov_label(! (encoding > 2 || encoding < 0),8,"DC");
  if (encoding > 2 || encoding < 0) goto return_label;
  next = 0;
  i = 0;
  while (1) {
    cov_label((int)*(string + next) != 0,9,"DC");
    cov_label(! ((int)*(string + next) != 0),10,"DC");
    if (! ((int)*(string + next) != 0)) break;
    ch = (int)*(string + next);
    cov_label(ch == '\r',11,"DC");
    cov_label(! (ch == '\r'),12,"DC");
    if (ch == '\r') {
      next ++;
      goto __Cont;
    }
    cov_label(ch == '\n',13,"DC");
    cov_label(! (ch == '\n'),14,"DC");
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
        cov_label(byte == '&',15,"DC");
        cov_label(! (byte == '&'),16,"DC");
        if (byte == '&') {
          byte = (int)((unsigned char)*(string + (next + 1)));
          cov_label(byte == '#',17,"DC");
          cov_label(! (byte == '#'),18,"DC");
          if (byte == '#') {
            byte = (int)((unsigned char)*(string + (next + 2)));
            cov_label(byte == 'x' || byte == 'X',19,"DC");
            cov_label(! (byte == 'x' || byte == 'X'),20,"DC");
            if (byte == 'x' || byte == 'X') {
              ii = 3;
              while (1) {
                cov_label(ii < 8,21,"DC");
                cov_label(! (ii < 8),22,"DC");
                if (! (ii < 8)) break;
                byte = (int)((unsigned char)*(string + (next + ii)));
                cov_label(byte >= 'A' && byte <= 'F',23,"DC");
                cov_label(! (byte >= 'A' && byte <= 'F'),24,"DC");
                if (byte >= 'A' && byte <= 'F') byte = (byte - 'A') + 10;
                else {
                  cov_label(byte >= 'a' && byte <= 'f',25,"DC");
                  cov_label(! (byte >= 'a' && byte <= 'f'),26,"DC");
                  if (byte >= 'a' && byte <= 'f') byte = (byte - 'a') + 10;
                  else {
                    cov_label(byte >= '0' && byte <= '9',27,"DC");
                    cov_label(! (byte >= '0' && byte <= '9'),28,"DC");
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
                cov_label(ii < 8,29,"DC");
                cov_label(! (ii < 8),30,"DC");
                if (! (ii < 8)) break;
                byte = (int)((unsigned char)*(string + (next + ii)));
                cov_label(byte >= '0' && byte <= '9',31,"DC");
                cov_label(! (byte >= '0' && byte <= '9'),32,"DC");
                if (byte >= '0' && byte <= '9') n = n * 10 + (byte - '0');
                else break;
                ii ++;
              }
            }
            cov_label(byte == ';',33,"DC");
            cov_label(! (byte == ';'),34,"DC");
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
              cov_label(ii < 1 + 8,35,"DC");
              cov_label(! (ii < 1 + 8),36,"DC");
              if (! (ii < 1 + 8)) break;
              byte = (int)((unsigned char)*(string + (next + ii)));
              cov_label(byte == 0,37,"DC");
              cov_label(! (byte == 0),38,"DC");
              if (byte == 0) break;
              cov_label(byte == ';',39,"DC");
              cov_label(! (byte == ';'),40,"DC");
              if (byte == ';') {
                *(p + indiceP) = (char)0;
                indiceP ++;
                res = search(key,entities,3);
                cov_label(res != 0,41,"DC");
                cov_label(! (res != 0),42,"DC");
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
        cov_label(byte < 0xC0,43,"DC");
        cov_label(! (byte < 0xC0),44,"DC");
        if (byte < 0xC0) len = 1;
        else {
          cov_label(byte < 0xE0,45,"DC");
          cov_label(! (byte < 0xE0),46,"DC");
          if (byte < 0xE0) {
            cov_label(((int)*(string + (next + 1)) & 0xC0) == 0x80,47,"DC");
            cov_label(! (((int)*(string + (next + 1)) & 0xC0) == 0x80),48,
                     "DC");
            if (((int)*(string + (next + 1)) & 0xC0) == 0x80) len = 2;
            len = 1;
          }
          else {
            cov_label(byte < 0xF0,49,"DC");
            cov_label(! (byte < 0xF0),50,"DC");
            if (byte < 0xF0) {
              cov_label(((int)*(string + (next + 1)) & 0xC0) == 0x80 && 
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80,51,"DC");
              cov_label(! (((int)*(string + (next + 1)) & 0xC0) == 0x80 && 
                          ((int)*(string + (next + 2)) & 0xC0) == 0x80),52,
                       "DC");
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
        cov_label(0xA1 <= (int)c && (int)c <= 0xFE,53,"DC");
        cov_label(! (0xA1 <= (int)c && (int)c <= 0xFE),54,"DC");
        if (0xA1 <= (int)c && (int)c <= 0xFE) next ++;
        cov_label((int)*(string + next) != 0,55,"DC");
        cov_label(! ((int)*(string + next) != 0),56,"DC");
        if ((int)*(string + next) != 0) next ++;
      }
      break;
      case 2:
      {
        ch = (int)*(string + next) & 0xFF;
        next ++;
        cov_label(ch >= 161 && (int)*(string + next) != 0,57,"DC");
        cov_label(! (ch >= 161 && (int)*(string + next) != 0),58,"DC");
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
