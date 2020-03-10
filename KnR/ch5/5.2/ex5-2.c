/* Write getfloat, the floating point analog of getint. What type does getfloat return as its function value */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 10
#define LEFT 1
#define RIGHT 0

int getch(void);
void ungetch(int);
int getline(char s[], int lim);

/* getfloat: get next integer from input into *pn */
float getfloat(float *pn)
{
  int c, sign, place = LEFT;
  float i;

  while (isspace(c = getch()))        /* skip whitespace */
    ;
 
  if (!isdigit(c) && c != '+' && c != '-' && c != '.' && c != EOF)  {
    ungetch(c);                       /* it's not a number */
    return 0;
  }

  sign = (c == '-') ? -1:1;

  if (c == '+' || c == '-') 
    c = getch();
  else if (c == '.')  {
    c = getch();
    place = RIGHT;
  }

  if ( !isdigit(c) )  {
    ungetch(c);
    ungetch(c);
    return 0;
  }

    for ( *pn = 0; isdigit(c); c = getch() )
      *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c == '.') {
      place = RIGHT;
      c = getch();
    }

  if (place == RIGHT) {
    for ( i = 10.0; isdigit(c); c = getch(), (i = i * 10.0))
      *pn = *pn + ((c - '0')/i);
  }

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
  int n, i, res;
  float array[SIZE];

  for (n = 0; n < SIZE && (res = getfloat(&array[n])) != EOF; ++n)
    ;

  /* print squares of each number as a test */
  for (i = 0; i < n; ++i)
    printf("\nnum - %lf square - %lf\n", array[i], array[i] * array[i]);
}
