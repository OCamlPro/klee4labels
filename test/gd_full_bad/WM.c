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
   cov_label((s1 != s2) != (s1 == s2),1,"WM ROR");
   cov_label(s1 < 0,2,"WM ABS");
   cov_label(s2 < 0,3,"WM ABS");
   if (s1 == s2) {
     __retres = 0;
     goto return_label;
   }
   while (1) {
     char const *tmp_0;
     char const *tmp;
     cov_label(s2 < 0,4,"WM ABS");
     tmp_0 = s2;
     cov_label(s2 < 0,5,"WM ABS");
     s2 ++;
     ;
     cov_label(((int)*s1 != (int)*tmp_0) != ((int)*s1 == (int)*tmp_0),6,
              "WM ROR");
     if (! ((int)*s1 == (int)*tmp_0)) break;
     cov_label(s1 < 0,7,"WM ABS");
     tmp = s1;
     cov_label(s1 < 0,8,"WM ABS");
     s1 ++;
     ;
     cov_label(((int)*tmp != '\000') != ((int)*tmp == '\000'),9,"WM ROR");
     if ((int)*tmp == '\000') {
       __retres = 0;
       goto return_label;
     }
   }
   cov_label(s2 < 0,10,"WM ABS");
   s2 --;
   ;
   cov_label((int)*((unsigned char *)s1) * (int)*((unsigned char *)s2) != 
            (int)*((unsigned char *)s1) - (int)*((unsigned char *)s2),11,
            "WM AOR");
   cov_label((int)*((unsigned char *)s1) / (int)*((unsigned char *)s2) != 
            (int)*((unsigned char *)s1) - (int)*((unsigned char *)s2),12,
            "WM AOR");
   cov_label((int)*((unsigned char *)s1) + (int)*((unsigned char *)s2) != 
            (int)*((unsigned char *)s1) - (int)*((unsigned char *)s2),13,
            "WM AOR");
   __retres = (int)*((unsigned char *)s1) - (int)*((unsigned char *)s2);
   return_label: {
                   cov_label(__retres < 0,14,"WM ABS");
                   return __retres;
                 }
 }

int search(char *keyName, char **base, int nmemb)
{
  int __retres;
  int iter;
  __retres = 1;
  cov_label(__retres < 0,15,"WM ABS");
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
  cov_label(nondetEntry < 0,16,"WM ABS");
  encoding = nondetEntry;
  cov_label((encoding > 2 && encoding < 0) != (encoding > 2 || encoding < 0),
           17,"WM COR");
  cov_label((encoding < 2) != (encoding > 2),18,"WM ROR");
  cov_label((encoding <= 2) != (encoding > 2),19,"WM ROR");
  cov_label((encoding >= 2) != (encoding > 2),20,"WM ROR");
  cov_label(encoding < 0,21,"WM ABS");
  cov_label((encoding <= 0) != (encoding < 0),22,"WM ROR");
  cov_label((encoding > 0) != (encoding < 0),23,"WM ROR");
  cov_label((encoding >= 0) != (encoding < 0),24,"WM ROR");
  cov_label(encoding < 0,25,"WM ABS");
  if (encoding > 2 || encoding < 0) goto return_label;
  next = 0;
  i = 0;
  while (1) {
    cov_label(((int)*(string + next) == 0) != ((int)*(string + next) != 0),26,
             "WM ROR");
    if (! ((int)*(string + next) != 0)) break;
    ch = (int)*(string + next);
    cov_label((ch != '\r') != (ch == '\r'),27,"WM ROR");
    cov_label(ch < 0,28,"WM ABS");
    if (ch == '\r') {
      cov_label(next * 1 != next + 1,29,"WM AOR");
      cov_label(next / 1 != next + 1,30,"WM AOR");
      cov_label(next - 1 != next + 1,31,"WM AOR");
      cov_label(next < 0,32,"WM ABS");
      next ++;
      goto __Cont;
    }
    cov_label((ch != '\n') != (ch == '\n'),33,"WM ROR");
    cov_label(ch < 0,34,"WM ABS");
    if (ch == '\n') {
      cov_label(next * 1 != next + 1,35,"WM AOR");
      cov_label(next / 1 != next + 1,36,"WM AOR");
      cov_label(next - 1 != next + 1,37,"WM AOR");
      cov_label(next < 0,38,"WM ABS");
      next ++;
      goto __Cont;
    }
    cov_label(encoding < 0,39,"WM ABS");
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
        cov_label((byte != '&') != (byte == '&'),40,"WM ROR");
        cov_label(byte < 0,41,"WM ABS");
        if (byte == '&') {
          byte = (int)((unsigned char)*(string + (next + 1)));
          cov_label((byte != '#') != (byte == '#'),42,"WM ROR");
          cov_label(byte < 0,43,"WM ABS");
          if (byte == '#') {
            byte = (int)((unsigned char)*(string + (next + 2)));
            cov_label((byte == 'x' && byte == 'X') != (byte == 'x' || 
                                                      byte == 'X'),44,
                     "WM COR");
            cov_label((byte != 'x') != (byte == 'x'),45,"WM ROR");
            cov_label(byte < 0,46,"WM ABS");
            cov_label((byte != 'X') != (byte == 'X'),47,"WM ROR");
            cov_label(byte < 0,48,"WM ABS");
            if (byte == 'x' || byte == 'X') {
              ii = 3;
              while (1) {
                cov_label((ii <= 8) != (ii < 8),49,"WM ROR");
                cov_label((ii > 8) != (ii < 8),50,"WM ROR");
                cov_label((ii >= 8) != (ii < 8),51,"WM ROR");
                cov_label(ii < 0,52,"WM ABS");
                if (! (ii < 8)) break;
                byte = (int)((unsigned char)*(string + (next + ii)));
                cov_label((byte >= 'A' || byte <= 'F') != (byte >= 'A' && 
                                                          byte <= 'F'),53,
                         "WM COR");
                cov_label((byte < 'A') != (byte >= 'A'),54,"WM ROR");
                cov_label((byte <= 'A') != (byte >= 'A'),55,"WM ROR");
                cov_label((byte > 'A') != (byte >= 'A'),56,"WM ROR");
                cov_label(byte < 0,57,"WM ABS");
                cov_label((byte < 'F') != (byte <= 'F'),58,"WM ROR");
                cov_label((byte > 'F') != (byte <= 'F'),59,"WM ROR");
                cov_label((byte >= 'F') != (byte <= 'F'),60,"WM ROR");
                cov_label(byte < 0,61,"WM ABS");
                if (byte >= 'A' && byte <= 'F') {
                  cov_label((byte - 'A') * 10 != (byte - 'A') + 10,62,
                           "WM AOR");
                  cov_label((byte - 'A') / 10 != (byte - 'A') + 10,63,
                           "WM AOR");
                  cov_label((byte - 'A') - 10 != (byte - 'A') + 10,64,
                           "WM AOR");
                  cov_label(byte * 'A' != byte - 'A',65,"WM AOR");
                  cov_label(byte / 'A' != byte - 'A',66,"WM AOR");
                  cov_label(byte + 'A' != byte - 'A',67,"WM AOR");
                  cov_label(byte < 0,68,"WM ABS");
                  byte = (byte - 'A') + 10;
                }
                else {
                  cov_label((byte >= 'a' || byte <= 'f') != (byte >= 'a' && 
                                                            byte <= 'f'),69,
                           "WM COR");
                  cov_label((byte < 'a') != (byte >= 'a'),70,"WM ROR");
                  cov_label((byte <= 'a') != (byte >= 'a'),71,"WM ROR");
                  cov_label((byte > 'a') != (byte >= 'a'),72,"WM ROR");
                  cov_label(byte < 0,73,"WM ABS");
                  cov_label((byte < 'f') != (byte <= 'f'),74,"WM ROR");
                  cov_label((byte > 'f') != (byte <= 'f'),75,"WM ROR");
                  cov_label((byte >= 'f') != (byte <= 'f'),76,"WM ROR");
                  cov_label(byte < 0,77,"WM ABS");
                  if (byte >= 'a' && byte <= 'f') {
                    cov_label((byte - 'a') * 10 != (byte - 'a') + 10,78,
                             "WM AOR");
                    cov_label((byte - 'a') / 10 != (byte - 'a') + 10,79,
                             "WM AOR");
                    cov_label((byte - 'a') - 10 != (byte - 'a') + 10,80,
                             "WM AOR");
                    cov_label(byte * 'a' != byte - 'a',81,"WM AOR");
                    cov_label(byte / 'a' != byte - 'a',82,"WM AOR");
                    cov_label(byte + 'a' != byte - 'a',83,"WM AOR");
                    cov_label(byte < 0,84,"WM ABS");
                    byte = (byte - 'a') + 10;
                  }
                  else {
                    cov_label((byte >= '0' || byte <= '9') != (byte >= '0' && 
                                                              byte <= '9'),
                             85,"WM COR");
                    cov_label((byte < '0') != (byte >= '0'),86,"WM ROR");
                    cov_label((byte <= '0') != (byte >= '0'),87,"WM ROR");
                    cov_label((byte > '0') != (byte >= '0'),88,"WM ROR");
                    cov_label(byte < 0,89,"WM ABS");
                    cov_label((byte < '9') != (byte <= '9'),90,"WM ROR");
                    cov_label((byte > '9') != (byte <= '9'),91,"WM ROR");
                    cov_label((byte >= '9') != (byte <= '9'),92,"WM ROR");
                    cov_label(byte < 0,93,"WM ABS");
                    if (byte >= '0' && byte <= '9') {
                      cov_label(byte * '0' != byte - '0',94,"WM AOR");
                      cov_label(byte / '0' != byte - '0',95,"WM AOR");
                      cov_label(byte + '0' != byte - '0',96,"WM AOR");
                      cov_label(byte < 0,97,"WM ABS");
                      byte -= '0';
                    }
                    else break;
                  }
                }
                cov_label((n * 16) * byte != n * 16 + byte,98,"WM AOR");
                cov_label((n * 16) / byte != n * 16 + byte,99,"WM AOR");
                cov_label(n * 16 - byte != n * 16 + byte,100,"WM AOR");
                cov_label(n / 16 != n * 16,101,"WM AOR");
                cov_label(n + 16 != n * 16,102,"WM AOR");
                cov_label(n - 16 != n * 16,103,"WM AOR");
                cov_label(n < 0,104,"WM ABS");
                cov_label(byte < 0,105,"WM ABS");
                n = n * 16 + byte;
                cov_label(ii * 1 != ii + 1,106,"WM AOR");
                cov_label(ii / 1 != ii + 1,107,"WM AOR");
                cov_label(ii - 1 != ii + 1,108,"WM AOR");
                cov_label(ii < 0,109,"WM ABS");
                ii ++;
              }
            }
            else {
              ii = 2;
              while (1) {
                cov_label((ii <= 8) != (ii < 8),110,"WM ROR");
                cov_label((ii > 8) != (ii < 8),111,"WM ROR");
                cov_label((ii >= 8) != (ii < 8),112,"WM ROR");
                cov_label(ii < 0,113,"WM ABS");
                if (! (ii < 8)) break;
                byte = (int)((unsigned char)*(string + (next + ii)));
                cov_label((byte >= '0' || byte <= '9') != (byte >= '0' && 
                                                          byte <= '9'),114,
                         "WM COR");
                cov_label((byte < '0') != (byte >= '0'),115,"WM ROR");
                cov_label((byte <= '0') != (byte >= '0'),116,"WM ROR");
                cov_label((byte > '0') != (byte >= '0'),117,"WM ROR");
                cov_label(byte < 0,118,"WM ABS");
                cov_label((byte < '9') != (byte <= '9'),119,"WM ROR");
                cov_label((byte > '9') != (byte <= '9'),120,"WM ROR");
                cov_label((byte >= '9') != (byte <= '9'),121,"WM ROR");
                cov_label(byte < 0,122,"WM ABS");
                if (byte >= '0' && byte <= '9') {
                  cov_label((n * 10) * (byte - '0') != n * 10 + (byte - '0'),
                           123,"WM AOR");
                  cov_label((n * 10) / (byte - '0') != n * 10 + (byte - '0'),
                           124,"WM AOR");
                  cov_label(n * 10 - (byte - '0') != n * 10 + (byte - '0'),
                           125,"WM AOR");
                  cov_label(n / 10 != n * 10,126,"WM AOR");
                  cov_label(n + 10 != n * 10,127,"WM AOR");
                  cov_label(n - 10 != n * 10,128,"WM AOR");
                  cov_label(n < 0,129,"WM ABS");
                  cov_label(byte * '0' != byte - '0',130,"WM AOR");
                  cov_label(byte / '0' != byte - '0',131,"WM AOR");
                  cov_label(byte + '0' != byte - '0',132,"WM AOR");
                  cov_label(byte < 0,133,"WM ABS");
                  n = n * 10 + (byte - '0');
                }
                else break;
                cov_label(ii * 1 != ii + 1,134,"WM AOR");
                cov_label(ii / 1 != ii + 1,135,"WM AOR");
                cov_label(ii - 1 != ii + 1,136,"WM AOR");
                cov_label(ii < 0,137,"WM ABS");
                ii ++;
              }
            }
            cov_label((byte != ';') != (byte == ';'),138,"WM ROR");
            cov_label(byte < 0,139,"WM ABS");
            if (byte == ';') {
              cov_label(ii * 1 != ii + 1,140,"WM AOR");
              cov_label(ii / 1 != ii + 1,141,"WM AOR");
              cov_label(ii - 1 != ii + 1,142,"WM AOR");
              cov_label(ii < 0,143,"WM ABS");
              ii ++;
              cov_label(ii < 0,144,"WM ABS");
              len = ii;
              goto endFun;
            }
          }
          else {
            p = entity_name_buf;
            cov_label(p < 0,145,"WM ABS");
            key = p;
            ii = 1;
            while (1) {
              cov_label((ii <= 1 + 8) != (ii < 1 + 8),146,"WM ROR");
              cov_label((ii > 1 + 8) != (ii < 1 + 8),147,"WM ROR");
              cov_label((ii >= 1 + 8) != (ii < 1 + 8),148,"WM ROR");
              cov_label(ii < 0,149,"WM ABS");
              cov_label(1 * 8 != 1 + 8,150,"WM AOR");
              cov_label(1 / 8 != 1 + 8,151,"WM AOR");
              cov_label(1 - 8 != 1 + 8,152,"WM AOR");
              if (! (ii < 1 + 8)) break;
              byte = (int)((unsigned char)*(string + (next + ii)));
              cov_label((byte != 0) != (byte == 0),153,"WM ROR");
              cov_label(byte < 0,154,"WM ABS");
              if (byte == 0) break;
              cov_label((byte != ';') != (byte == ';'),155,"WM ROR");
              cov_label(byte < 0,156,"WM ABS");
              if (byte == ';') {
                *(p + indiceP) = (char)0;
                cov_label(indiceP * 1 != indiceP + 1,157,"WM AOR");
                cov_label(indiceP / 1 != indiceP + 1,158,"WM AOR");
                cov_label(indiceP - 1 != indiceP + 1,159,"WM AOR");
                cov_label(indiceP < 0,160,"WM ABS");
                indiceP ++;
                res = search(key,entities,3);
                cov_label((res == 0) != (res != 0),161,"WM ROR");
                cov_label(res < 0,162,"WM ABS");
                if (res != 0) {
                  cov_label(ii * 1 != ii + 1,163,"WM AOR");
                  cov_label(ii / 1 != ii + 1,164,"WM AOR");
                  cov_label(ii - 1 != ii + 1,165,"WM AOR");
                  cov_label(ii < 0,166,"WM ABS");
                  ii ++;
                  cov_label(ii < 0,167,"WM ABS");
                  len = ii;
                  goto endFun;
                }
                break;
              }
              *(p + indiceP) = (char)byte;
              cov_label(indiceP * 1 != indiceP + 1,168,"WM AOR");
              cov_label(indiceP / 1 != indiceP + 1,169,"WM AOR");
              cov_label(indiceP - 1 != indiceP + 1,170,"WM AOR");
              cov_label(indiceP < 0,171,"WM ABS");
              indiceP ++;
              cov_label(ii * 1 != ii + 1,172,"WM AOR");
              cov_label(ii / 1 != ii + 1,173,"WM AOR");
              cov_label(ii - 1 != ii + 1,174,"WM AOR");
              cov_label(ii < 0,175,"WM ABS");
              ii ++;
            }
          }
        }
        len = 1;
        byte = (int)((unsigned char)*(string + next));
        cov_label((byte <= 0xC0) != (byte < 0xC0),176,"WM ROR");
        cov_label((byte > 0xC0) != (byte < 0xC0),177,"WM ROR");
        cov_label((byte >= 0xC0) != (byte < 0xC0),178,"WM ROR");
        cov_label(byte < 0,179,"WM ABS");
        if (byte < 0xC0) len = 1;
        else {
          cov_label((byte <= 0xE0) != (byte < 0xE0),180,"WM ROR");
          cov_label((byte > 0xE0) != (byte < 0xE0),181,"WM ROR");
          cov_label((byte >= 0xE0) != (byte < 0xE0),182,"WM ROR");
          cov_label(byte < 0,183,"WM ABS");
          if (byte < 0xE0) {
            cov_label((((int)*(string + (next + 1)) & 0xC0) != 0x80) != (
                     ((int)*(string + (next + 1)) & 0xC0) == 0x80),184,
                     "WM ROR");
            if (((int)*(string + (next + 1)) & 0xC0) == 0x80) len = 2;
            len = 1;
          }
          else {
            cov_label((byte <= 0xF0) != (byte < 0xF0),185,"WM ROR");
            cov_label((byte > 0xF0) != (byte < 0xF0),186,"WM ROR");
            cov_label((byte >= 0xF0) != (byte < 0xF0),187,"WM ROR");
            cov_label(byte < 0,188,"WM ABS");
            if (byte < 0xF0) {
              cov_label((((int)*(string + (next + 1)) & 0xC0) == 0x80 || 
                        ((int)*(string + (next + 2)) & 0xC0) == 0x80) != (
                       ((int)*(string + (next + 1)) & 0xC0) == 0x80 && 
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80),189,
                       "WM COR");
              cov_label((((int)*(string + (next + 1)) & 0xC0) != 0x80) != (
                       ((int)*(string + (next + 1)) & 0xC0) == 0x80),190,
                       "WM ROR");
              cov_label((((int)*(string + (next + 2)) & 0xC0) != 0x80) != (
                       ((int)*(string + (next + 2)) & 0xC0) == 0x80),191,
                       "WM ROR");
              if (((int)*(string + (next + 1)) & 0xC0) == 0x80 && ((int)*(
                                                                   string + (
                                                                   next + 2)) & 0xC0) == 0x80) 
                len = 3;
              len = 1;
            }
          }
        }
        endFun:
        {
          cov_label(next * len != next + len,192,"WM AOR");
          cov_label(next / len != next + len,193,"WM AOR");
          cov_label(next - len != next + len,194,"WM AOR");
          cov_label(next < 0,195,"WM ABS");
          cov_label(len < 0,196,"WM ABS");
          next += len;
        }
      }
      break;
      case 1:
      {
        unsigned char c;
        c = (unsigned char)*(string + next);
        cov_label((0xA1 <= (int)c || (int)c <= 0xFE) != (0xA1 <= (int)c && 
                                                        (int)c <= 0xFE),197,
                 "WM COR");
        cov_label((0xA1 < (int)c) != (0xA1 <= (int)c),198,"WM ROR");
        cov_label((0xA1 > (int)c) != (0xA1 <= (int)c),199,"WM ROR");
        cov_label((0xA1 >= (int)c) != (0xA1 <= (int)c),200,"WM ROR");
        cov_label(((int)c < 0xFE) != ((int)c <= 0xFE),201,"WM ROR");
        cov_label(((int)c > 0xFE) != ((int)c <= 0xFE),202,"WM ROR");
        cov_label(((int)c >= 0xFE) != ((int)c <= 0xFE),203,"WM ROR");
        if (0xA1 <= (int)c && (int)c <= 0xFE) {
          cov_label(next * 1 != next + 1,204,"WM AOR");
          cov_label(next / 1 != next + 1,205,"WM AOR");
          cov_label(next - 1 != next + 1,206,"WM AOR");
          cov_label(next < 0,207,"WM ABS");
          next ++;
        }
        cov_label(((int)*(string + next) == 0) != ((int)*(string + next) != 0),
                 208,"WM ROR");
        if ((int)*(string + next) != 0) {
          cov_label(next * 1 != next + 1,209,"WM AOR");
          cov_label(next / 1 != next + 1,210,"WM AOR");
          cov_label(next - 1 != next + 1,211,"WM AOR");
          cov_label(next < 0,212,"WM ABS");
          next ++;
        }
      }
      break;
      case 2:
      {
        ch = (int)*(string + next) & 0xFF;
        cov_label(next * 1 != next + 1,213,"WM AOR");
        cov_label(next / 1 != next + 1,214,"WM AOR");
        cov_label(next - 1 != next + 1,215,"WM AOR");
        cov_label(next < 0,216,"WM ABS");
        next ++;
        cov_label((ch >= 161 || (int)*(string + next) != 0) != (ch >= 161 && 
                                                               (int)*(
                                                               string + next) != 0),
                 217,"WM COR");
        cov_label((ch < 161) != (ch >= 161),218,"WM ROR");
        cov_label((ch <= 161) != (ch >= 161),219,"WM ROR");
        cov_label((ch > 161) != (ch >= 161),220,"WM ROR");
        cov_label(ch < 0,221,"WM ABS");
        cov_label(((int)*(string + next) == 0) != ((int)*(string + next) != 0),
                 222,"WM ROR");
        if (ch >= 161 && (int)*(string + next) != 0) {
          cov_label(next * 1 != next + 1,223,"WM AOR");
          cov_label(next / 1 != next + 1,224,"WM AOR");
          cov_label(next - 1 != next + 1,225,"WM AOR");
          cov_label(next < 0,226,"WM ABS");
          next ++;
        }
      }
      break;
    }
    __Cont:
    {
      cov_label(i * 1 != i + 1,227,"WM AOR");
      cov_label(i / 1 != i + 1,228,"WM AOR");
      cov_label(i - 1 != i + 1,229,"WM AOR");
      cov_label(i < 0,230,"WM ABS");
      i ++;
    }
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
