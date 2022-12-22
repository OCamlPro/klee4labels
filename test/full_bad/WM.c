#include "errno.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "harness_macros.h"

#ifndef cov_label
#define cov_label(...) do{}while(0)
#endif

int loopcnt;
unsigned int mystrlen(char *s)
{
  unsigned int __retres;
  int i;
  i = 0;
  while (1) {
    cov_label(((int)*(s + i) == 0) != ((int)*(s + i) != 0),1,"WM ROR");
    if (! ((int)*(s + i) != 0)) break;
    cov_label(i * 1 != i + 1,2,"WM AOR");
    cov_label(i / 1 != i + 1,3,"WM AOR");
    cov_label(i - 1 != i + 1,4,"WM AOR");
    cov_label(i < 0,5,"WM ABS");
    i ++;
  }
  __retres = (unsigned int)i;
  cov_label(__retres < 0,6,"WM ABS");
  return __retres;
}

int mystrncmp(char const *s1, char const *s2, int n)
{
  int __retres;
  int i;
  int retval;
  i = 0;
  while (1) {
    cov_label((int)*(s1 + i) * (int)*(s2 + i) != (int)*(s1 + i) - (int)*(
                                                s2 + i),7,"WM AOR");
    cov_label((int)*(s1 + i) / (int)*(s2 + i) != (int)*(s1 + i) - (int)*(
                                                s2 + i),8,"WM AOR");
    cov_label((int)*(s1 + i) + (int)*(s2 + i) != (int)*(s1 + i) - (int)*(
                                                s2 + i),9,"WM AOR");
    retval = (int)*(s1 + i) - (int)*(s2 + i);
    cov_label((i < n - 1) != (i >= n - 1),10,"WM ROR");
    cov_label((i <= n - 1) != (i >= n - 1),11,"WM ROR");
    cov_label((i > n - 1) != (i >= n - 1),12,"WM ROR");
    cov_label(i < 0,13,"WM ABS");
    cov_label(n * 1 != n - 1,14,"WM AOR");
    cov_label(n / 1 != n - 1,15,"WM AOR");
    cov_label(n + 1 != n - 1,16,"WM AOR");
    cov_label(n < 0,17,"WM ABS");
    if (i >= n - 1) {
      cov_label(retval < 0,18,"WM ABS");
      __retres = retval;
      goto return_label;
    }
    cov_label((retval == 0) != (retval != 0),19,"WM ROR");
    cov_label(retval < 0,20,"WM ABS");
    if (retval != 0) {
      cov_label(retval < 0,21,"WM ABS");
      __retres = retval;
      goto return_label;
    }
    cov_label(((int)*(s1 + i) != 0) != ((int)*(s1 + i) == 0),22,"WM ROR");
    if ((int)*(s1 + i) == 0) {
      __retres = 0;
      goto return_label;
    }
    cov_label(i * 1 != i + 1,23,"WM AOR");
    cov_label(i / 1 != i + 1,24,"WM AOR");
    cov_label(i - 1 != i + 1,25,"WM AOR");
    cov_label(i < 0,26,"WM ABS");
    i ++;
  }
  return_label: {
                  cov_label(__retres < 0,27,"WM ABS");
                  return __retres;
                }
}

void escape_absolute_uri(char *uri, int scheme)
{
  int cp;
  int c;
  int i;
  char *token[2 + 1];
  loopcnt = 0;
  char LDAP[5] = {(char)'l', (char)'d', (char)'a', (char)'p', (char)'\000'};
  cov_label((scheme != 0) != (scheme == 0),28,"WM ROR");
  cov_label(scheme < 0,29,"WM ABS");
  if (scheme == 0) goto _LOR;
  else {
    unsigned int tmp;
    tmp = mystrlen(uri);
    ;
    cov_label((tmp <= (unsigned int)scheme) != (tmp < (unsigned int)scheme),
             30,"WM ROR");
    cov_label((tmp > (unsigned int)scheme) != (tmp < (unsigned int)scheme),31,
             "WM ROR");
    cov_label((tmp >= (unsigned int)scheme) != (tmp < (unsigned int)scheme),
             32,"WM ROR");
    cov_label(tmp < 0,33,"WM ABS");
    if (tmp < (unsigned int)scheme) _LOR: goto return_label;
  }
  cov_label(scheme < 0,34,"WM ABS");
  cp = scheme;
  cov_label(((int)*(uri + (cp - 1)) != '/') != ((int)*(uri + (cp - 1)) == '/'),
           35,"WM ROR");
  if ((int)*(uri + (cp - 1)) == '/') {
    int tmp_0;
    while (1) {
      cov_label(((int)*(uri + cp) != 0 || (int)*(uri + cp) != '/') != (
               (int)*(uri + cp) != 0 && (int)*(uri + cp) != '/'),36,"WM COR");
      cov_label(((int)*(uri + cp) == 0) != ((int)*(uri + cp) != 0),37,
               "WM ROR");
      cov_label(((int)*(uri + cp) == '/') != ((int)*(uri + cp) != '/'),38,
               "WM ROR");
      if (! ((int)*(uri + cp) != 0 && (int)*(uri + cp) != '/')) break;
      cov_label(loopcnt * 1 != loopcnt + 1,39,"WM AOR");
      cov_label(loopcnt / 1 != loopcnt + 1,40,"WM AOR");
      cov_label(loopcnt - 1 != loopcnt + 1,41,"WM AOR");
      cov_label(loopcnt < 0,42,"WM ABS");
      loopcnt ++;
      cov_label((loopcnt < 100) != (loopcnt >= 100),43,"WM ROR");
      cov_label((loopcnt <= 100) != (loopcnt >= 100),44,"WM ROR");
      cov_label((loopcnt > 100) != (loopcnt >= 100),45,"WM ROR");
      cov_label(loopcnt < 0,46,"WM ABS");
      if (loopcnt >= 100) goto return_label;
      cov_label(cp * 1 != cp + 1,47,"WM AOR");
      cov_label(cp / 1 != cp + 1,48,"WM AOR");
      cov_label(cp - 1 != cp + 1,49,"WM AOR");
      cov_label(cp < 0,50,"WM ABS");
      cp ++;
    }
    cov_label(((int)*(uri + cp) == 0 && (int)*(uri + (cp + 1)) == 0) != (
             (int)*(uri + cp) == 0 || (int)*(uri + (cp + 1)) == 0),51,
             "WM COR");
    cov_label(((int)*(uri + cp) != 0) != ((int)*(uri + cp) == 0),52,"WM ROR");
    cov_label(((int)*(uri + (cp + 1)) != 0) != ((int)*(uri + (cp + 1)) == 0),
             53,"WM ROR");
    if ((int)*(uri + cp) == 0 || (int)*(uri + (cp + 1)) == 0) goto return_label;
    cov_label(cp * 1 != cp + 1,54,"WM AOR");
    cov_label(cp / 1 != cp + 1,55,"WM AOR");
    cov_label(cp - 1 != cp + 1,56,"WM AOR");
    cov_label(cp < 0,57,"WM ABS");
    cp ++;
    cov_label(cp < 0,58,"WM ABS");
    scheme = cp;
    tmp_0 = mystrncmp((char const *)uri,(char const *)(LDAP),4);
    cov_label((tmp_0 != 0) != (tmp_0 == 0),59,"WM ROR");
    cov_label(tmp_0 < 0,60,"WM ABS");
    if (tmp_0 == 0) {
      c = 0;
      cov_label(uri < 0,61,"WM ABS");
      token[0] = uri;
      while (1) {
        cov_label(((int)*(uri + cp) != 0 || c < 2 + 1) != ((int)*(uri + cp) != 0 && 
                                                          c < 2 + 1),62,
                 "WM COR");
        cov_label(((int)*(uri + cp) == 0) != ((int)*(uri + cp) != 0),63,
                 "WM ROR");
        cov_label((c <= 2 + 1) != (c < 2 + 1),64,"WM ROR");
        cov_label((c > 2 + 1) != (c < 2 + 1),65,"WM ROR");
        cov_label((c >= 2 + 1) != (c < 2 + 1),66,"WM ROR");
        cov_label(c < 0,67,"WM ABS");
        cov_label(2 * 1 != 2 + 1,68,"WM AOR");
        cov_label(2 / 1 != 2 + 1,69,"WM AOR");
        cov_label(2 - 1 != 2 + 1,70,"WM AOR");
        if (! ((int)*(uri + cp) != 0 && c < 2 + 1)) break;
        cov_label(loopcnt * 1 != loopcnt + 1,71,"WM AOR");
        cov_label(loopcnt / 1 != loopcnt + 1,72,"WM AOR");
        cov_label(loopcnt - 1 != loopcnt + 1,73,"WM AOR");
        cov_label(loopcnt < 0,74,"WM ABS");
        loopcnt ++;
        cov_label((loopcnt < 100) != (loopcnt >= 100),75,"WM ROR");
        cov_label((loopcnt <= 100) != (loopcnt >= 100),76,"WM ROR");
        cov_label((loopcnt > 100) != (loopcnt >= 100),77,"WM ROR");
        cov_label(loopcnt < 0,78,"WM ABS");
        if (loopcnt >= 100) goto return_label;
        cov_label(((int)*(uri + cp) != '?') != ((int)*(uri + cp) == '?'),79,
                 "WM ROR");
        if ((int)*(uri + cp) == '?') {
          cov_label(c * 1 != c + 1,80,"WM AOR");
          cov_label(c / 1 != c + 1,81,"WM AOR");
          cov_label(c - 1 != c + 1,82,"WM AOR");
          cov_label(c < 0,83,"WM ABS");
          c ++;
          cov_label(uri < 0,84,"WM ABS");
          cov_label(cp < 0,85,"WM ABS");
          token[c] = (uri + cp) + 1;
          *(uri + cp) = (char)0;
        }
        cov_label(cp * 1 != cp + 1,86,"WM AOR");
        cov_label(cp / 1 != cp + 1,87,"WM AOR");
        cov_label(cp - 1 != cp + 1,88,"WM AOR");
        cov_label(cp < 0,89,"WM ABS");
        cp ++;
      }
      goto return_label;
    }
  }
  return_label: return;
}

#define _MAX_PTR_ARRAY_LENGTH 1
#define _MAX_CSTRING_LENGTH 10

static char _CSTRING_SYMBOL (v0)[11]; /* uri */

int main () {

  HARNESS_START;

  int scheme;
  char (* uri);

  _FLAT (scheme, "scheme", int);
  _FLAT (loopcnt, "loopcnt", int);
  _CSTRING_DECL (v0, "uri");
  _CSTRING_FILL (v0, "uri");
  uri = _CSTRING (v0);

  (void) escape_absolute_uri (uri, scheme);
  HARNESS_END;
  return 0;
}
