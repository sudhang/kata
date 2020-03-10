/* features to add:
D*    precision alongwith floats
D*    hexadecimal numbers
D*    unsigned numbers
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
  va_list ap;   /* points to each unnamed arg in turn */
  char *p, *sval;
  int ival, hval, uval;
  double dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++)  {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch(*++p)  {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      case '.':
        /* use the 'star' format */
        dval = va_arg(ap, double);
        if (isdigit(*(p+1)))
          printf("%.*f", atoi(++p), dval);
        else printf("%.f", dval);
        ++p;
        break;
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++)
          putchar(*sval);
        break;
      case 'x':
        hval = va_arg(ap, int);
        printf("%x", hval);
        break;
      case 'u':
        uval = va_arg(ap, int);
        printf("%u", uval);
        break;
      default:
        putchar(*p);
        break;
    }
    va_end(ap);   /* clean up */
  }
}

main()
{
  printf("printf %.3f\n", 1234.0913);
  minprintf("min %.3f\n", 1234.0913);
  printf("printf %.f\n", 1234.0913);
  minprintf("min %.f\n", 1234.0913);
}
