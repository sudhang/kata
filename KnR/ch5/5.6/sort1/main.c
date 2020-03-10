#include <string.h>
#include "sort.h"

/* sort input lines */
main()
{
  int nlines;       /* number of input lines read */

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else  {
    printf("error: input too big to sort\n");
    return 1;
  }
}
