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
#define MAXLINE 10000 /* max length of line received */

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

/* reverse Polish calculator */
int main(void)
{
  int type;
  double op1, op2;
  char s[MAXOP];

  while((type = getop(s)) != '\0')
  {
    switch(type)
    {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0)
          push( ((int) pop()) % ((int) op2));
        else
          printf("error: zero divisor \n");
        break;
      case '\n':                                                       // The final answer is printed
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s type - %d\n", s, type);
        break;
      case TOKEN:                                                     // A token is encountered. Should be a function though
        if ( strcmp(s, "sin") == 0 )  
          push(sin(pop()));
        else if ( strcmp(s, "cos") == 0 )
          push(cos(pop()));
        else if ( strcmp(s, "tan") == 0 )
          push(tan(pop()));
        else if ( strcmp(s, "pow") == 0 ) {
          op2 = pop();
          push(pow(pop(), op2));
        }
        else if ( strcmp(s, "tos") == 0 )  {
          op2 = pop();
          printf("top of stack: %lf\n", op2);
          push(op2);
        }
        else if ( strcmp(s, "cls") == 0 )
          clear();
        else if ( strcmp(s, "dup") == 0 ) {
          op2 = pop();
          push(op2);
          push(op2);
        }
        else if ( strcmp(s, "swp") == 0 ) {
          op1 = pop();
          op2 = pop();
          push(op1);
          push(op2);
        }
        else handleVar(s);
        break;
    }
  }

  return 0;
}

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
char line[MAXLINE];
int getline(char [], int);
int lp = 0;

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  if (lp == 0)
    getline(line,MAXLINE);

  while((s[0] = c = line[lp++]) == ' ' || c == '\t')   /* Skip leading whitespace */
    ;
  s[1] = '\0';

  i = 0;

  if (isalpha(c))  {      /* the character may be a single character, or part of a word */
    while (isalpha(s[++i] = c = line[lp++]))
      ;
    s[i] = '\0';
    if (c != '\0' && c != '\n')
      --lp;
    return TOKEN;
  }

  if(!isdigit(c) && c != '.' && c != '-' && c != '+') /* an operand, other than maybe + or - */
     return c;                 

  if(c == '+' || c == '-')  {
    if (isspace(s[++i] = c = line[lp++]))  {   /* it is an operand + or - */
      --lp;
      return s[0];
    }
  }

  while(isdigit(s[++i] = c = line[lp++]))
    ;
  if(c == '.')
    while(isdigit(s[++i] = c = line[lp++]))
      ;
  s[i] = '\0';
  if(c != '\n' && c != '\0')
    --lp;
  return NUMBER;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
