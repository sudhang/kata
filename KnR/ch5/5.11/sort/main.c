#include <string.h>
#include "sort.h"

/* sort input lines */
main(int argc, char **argv)
{
  int nlines;       /* number of input lines read */
  int numeric = 0;  /* 1 if numeric sort */

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort1( (void **) lineptr, 0, nlines - 1, (int (*)(const void *,const void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else  {
    printf("error: input too big to sort\n");
    return 1;
  }
}
