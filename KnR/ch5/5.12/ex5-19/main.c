#include "dcl.h"
int nexttoken(void)
{
  int type;
  type = gettoken();
  prevTokenExists = 1;
  return type;
}

main()    /* convert word description to declaration */
{
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF)   {
    strcpy(out, token);
    while ((type = gettoken()) != '\n') {
      if (type == PARENS || type == BRACKETS)
        strcat(out, token);
      else if (type == '*') {
        /* test the NEXT token, without actually putting it in the buffer */
        if ((type = nexttoken()) == PARENS || type == BRACKETS)  {
          /* explanation: the only operators with precedence over the (unary) * operation
           * are BRACKETS, PARENS and the -> operator.  If the next token is one of these
           * we will need to wrap the pointer operation and operand in parens to force the 
           * precedence specified in the input. (note: -> is not supported in our gettoken()
           */
          sprintf(temp, "(*%s)", out);
        }
        else  {
          sprintf(temp, "*%s", out);
        }
        strcpy(out, temp);
      } else if (type == NAME)  {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else 
        printf("invalid input at %s\n", token);
      }
      printf("%s\n", out);
  }
  return 0;
}
