#include <string.h>
#include "sort.h"
int reverse = 0;

/* sort input lines */
main(int argc, char **argv)
{
  int nlines;       /* number of input lines read */
  int numeric = 0;  /* 1 if yes */

  while (--argc > 0 && **++argv == '-')   {
    switch (*++argv[0])   {
      case 'n':
        numeric = 1;
        break;
      case 'r':
        reverse = 1;
        break;
      default:
        printf("invalid option\n");
        return;
    }
  }

  if (argc != 0)  {
    printf("usage: ./sort -n -r\n");
    return;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort1( (void **) lineptr, 0, nlines - 1, (int (*)(const void *,const void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else  {
    printf("error: input too big to sort\n");
    return 1;
  }
}
