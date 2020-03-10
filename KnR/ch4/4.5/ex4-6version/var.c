#include <string.h>
#include "calc.h"

#define MAXVARS 15
#define VARNAMELENGTH 10; /* max length of a variable name */

struct var {
  char *name;           //[VARNAMELENGTH]; Find out why I cannot use an array here! Is it because we cannot allot storage to a struct?
  double val;
} vars[MAXVARS];
int nvars = 0;

void handleVar(char s[])
{
  int i;

  for (i = 0; i < nvars; ++i) {
    if ( strcmp(s, vars[i].name) == 0 )
      push( vars[i].val );
    else  {
      vars[i].name = s;
      vars[i].val = pop();
      nvars++;
    }
  }
}
