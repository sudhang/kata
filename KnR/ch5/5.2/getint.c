#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 10

int getch(void);
void ungetch(int);
int getline(char s[], int lim);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))        /* skip whitespace */
    ;
 
  if (!isdigit(c) && c != '+' && c != '-' && c != EOF)  {
    ungetch(c);                       /* it's not a number */
    return 0;
  }

  sign = (c == '-') ? -1:1;

  if (c == '+' || c == '-')
    c = getch();
  for ( *pn = 0; isdigit(c); c = getch() )
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;

  if (c != EOF)
    ungetch(c);
  return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

main()
{
  int n, i, array[SIZE];

  for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n)
    ;

  /* print squares of each number as a test */
  for (i = 0; i < n; ++i)
    printf("\nnum - %d square - %d\n", array[i], array[i] * array[i]);
}
