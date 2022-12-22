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
    cov_label((int)*(s + i) != 0,1,"MCC");
    cov_label(! ((int)*(s + i) != 0),2,"MCC");
    if (! ((int)*(s + i) != 0)) break;
    i ++;
  }
  __retres = (unsigned int)i;
  return __retres;
}

int mystrncmp(char const *s1, char const *s2, int n)
{
  int __retres;
  int i;
  int retval;
  i = 0;
  while (1) {
    retval = (int)*(s1 + i) - (int)*(s2 + i);
    cov_label(i >= n - 1,3,"MCC");
    cov_label(! (i >= n - 1),4,"MCC");
    if (i >= n - 1) {
      __retres = retval;
      goto return_label;
    }
    cov_label(retval != 0,5,"MCC");
    cov_label(! (retval != 0),6,"MCC");
    if (retval != 0) {
      __retres = retval;
      goto return_label;
    }
    cov_label((int)*(s1 + i) == 0,7,"MCC");
    cov_label(! ((int)*(s1 + i) == 0),8,"MCC");
    if ((int)*(s1 + i) == 0) {
      __retres = 0;
      goto return_label;
    }
    i ++;
  }
  return_label: return __retres;
}

void escape_absolute_uri(char *uri, int scheme)
{
  int cp;
  int c;
  int i;
  char *token[2 + 1];
  loopcnt = 0;
  char LDAP[5] = {(char)'l', (char)'d', (char)'a', (char)'p', (char)'\000'};
  cov_label(scheme == 0,9,"MCC");
  cov_label(! (scheme == 0),10,"MCC");
  if (scheme == 0) goto _LOR;
  else {
    unsigned int tmp;
    tmp = mystrlen(uri);
    ;
    cov_label(tmp < (unsigned int)scheme,11,"MCC");
    cov_label(! (tmp < (unsigned int)scheme),12,"MCC");
    if (tmp < (unsigned int)scheme) _LOR: goto return_label;
  }
  cp = scheme;
  cov_label((int)*(uri + (cp - 1)) == '/',13,"MCC");
  cov_label(! ((int)*(uri + (cp - 1)) == '/'),14,"MCC");
  if ((int)*(uri + (cp - 1)) == '/') {
    int tmp_0;
    while (1) {
      cov_label((int)*(uri + cp) != 0 && (int)*(uri + cp) != 47,15,"MCC");
      cov_label((int)*(uri + cp) != 0 && ! ((int)*(uri + cp) != 47),16,"MCC");
      cov_label(! ((int)*(uri + cp) != 0) && (int)*(uri + cp) != 47,17,"MCC");
      cov_label(! ((int)*(uri + cp) != 0) && ! ((int)*(uri + cp) != 47),18,
               "MCC");
      if (! ((int)*(uri + cp) != 0 && (int)*(uri + cp) != '/')) break;
      loopcnt ++;
      cov_label(loopcnt >= 100,19,"MCC");
      cov_label(! (loopcnt >= 100),20,"MCC");
      if (loopcnt >= 100) goto return_label;
      cp ++;
    }
    cov_label((int)*(uri + cp) == 0 && (int)*(uri + (cp + 1)) == 0,21,"MCC");
    cov_label((int)*(uri + cp) == 0 && ! ((int)*(uri + (cp + 1)) == 0),22,
             "MCC");
    cov_label(! ((int)*(uri + cp) == 0) && (int)*(uri + (cp + 1)) == 0,23,
             "MCC");
    cov_label(! ((int)*(uri + cp) == 0) && ! ((int)*(uri + (cp + 1)) == 0),24,
             "MCC");
    if ((int)*(uri + cp) == 0 || (int)*(uri + (cp + 1)) == 0) goto return_label;
    cp ++;
    scheme = cp;
    tmp_0 = mystrncmp((char const *)uri,(char const *)(LDAP),4);
    cov_label(tmp_0 == 0,25,"MCC");
    cov_label(! (tmp_0 == 0),26,"MCC");
    if (tmp_0 == 0) {
      c = 0;
      token[0] = uri;
      while (1) {
        cov_label((int)*(uri + cp) != 0 && c < 3,27,"MCC");
        cov_label((int)*(uri + cp) != 0 && ! (c < 3),28,"MCC");
        cov_label(! ((int)*(uri + cp) != 0) && c < 3,29,"MCC");
        cov_label(! ((int)*(uri + cp) != 0) && ! (c < 3),30,"MCC");
        if (! ((int)*(uri + cp) != 0 && c < 2 + 1)) break;
        loopcnt ++;
        cov_label(loopcnt >= 100,31,"MCC");
        cov_label(! (loopcnt >= 100),32,"MCC");
        if (loopcnt >= 100) goto return_label;
        cov_label((int)*(uri + cp) == '?',33,"MCC");
        cov_label(! ((int)*(uri + cp) == '?'),34,"MCC");
        if ((int)*(uri + cp) == '?') {
          c ++;
          token[c] = (uri + cp) + 1;
          *(uri + cp) = (char)0;
        }
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


