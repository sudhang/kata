#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* minscanf: minimal scanf with variable length argument list */
void minscanf(char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);

  char *p, tmp, *t;
  int t1;

  for (p = fmt; p; p++) {
    switch(*p)  {
      case '%':
      case 'd':
      case 'f':
      case 's':
        break;
      case ' ':
      case '\t':
      case '\n':
        tmp = getc(stdin);
        while (tmp == ' ' || tmp == '\t' || tmp == '\n')
          tmp = getc(stdin);
        ungetc(tmp, stdin);
        continue;
      default:
        tmp = getc(stdin);
        if (*p != tmp)  {
          ungetc(tmp, stdin);
          return;
        }
        continue;
    }

    switch(*++p)  {
      case 'd':
        scanf("%d", va_arg(ap, int *));
        break;
      case 'f':
        scanf("%f", va_arg(ap, double *));
        break;
      case 's':
        scanf("%s", va_arg(ap, char *));
        break;
      default:
        break;
    }
  }
  va_end(ap);
}

main()
{
  int a;
  float b;
  char *s;

  s = (char *)malloc(sizeof(char));

  minscanf("%d    - %f", &a, &b);
  printf("int a %d float b %f\n", a, b);

  minscanf("%f", &b);
  printf("float %f\n", b);

  minscanf("%s\n", s);
  printf("string %s\n", s);
}
