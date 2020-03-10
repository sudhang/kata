/* reverse Polish calculator */

#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>
#include "calc.h"
#define MAXOP 100 /* max size of operand or operator */

/* reverse Polish calculator */
int main(void)
{
  int type;
  double op1, op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF)
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
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
      case TOKEN:
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
