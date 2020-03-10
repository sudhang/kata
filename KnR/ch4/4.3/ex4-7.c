/* this program forms the basis on which exercises 4-3 through 4-10 build */

#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <string.h> /* for strcmp() */
#include <math.h>   /* for math functions */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define TOKEN '1' /* signal that a token (word) was found */
#define VARNAMELENGTH 10; /* max length of a variable name */
#define MAXVARS 15  /* max number of variables */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void handleVar(char []);

struct var {
  char *name;           //[VARNAMELENGTH]; Find out why I cannot use an array here! Is it because we cannot allot storage to a struct?
  double val;
} vars[MAXVARS];
int nvars = 0;

#define MAXVAL  100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* clear: clear the stack */
void clear(void)
{
  sp = 0;
}

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

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')   /* Skip leading whitespace */
    ;
  s[1] = '\0';

  i = 0;

  if (isalpha(c))  {      /* the character may be a single character, or part of a word */
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    return TOKEN;
  }

  if(!isdigit(c) && c != '.' && c != '-' && c != '+') /* an operand, other than maybe + or - */
     return c;                 

  if(c == '+' || c == '-')  {
    if (isspace(s[++i] = c = getch()))  {   /* it is an operand + or - */
      ungetch(c);   
      return s[0];
    }
  }

  while(isdigit(s[++i] = c = getch()))
    ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

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

void ungets(char s[])
{
  int i; 

  for (i = strlen(s) - 1; i >= 0; --i)
    ungetch(s[i]);
}

int main(void)
{
  char *s = "hello, world.  this is a test.";
  int c;

  ungets(s);
  while ((c = getch()) != EOF)
    putchar(c);               
  return 0;
}
