#include "dcl.h"
/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
  int type;

  printf("tokentype is %d and the token is %s\n", tokentype, token);
  if (tokentype == '(') {
    if ( (type = nexttoken()) == NAME)  {
      gettoken();
      strcat(out, " function taking as parameter ");
      strcat(out, token);
      strcat(out, " returning");
    }
    dcl();
  printf("tokentype is %d and the token is %s\n", tokentype, token);
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME) {
    if (!nameDecided) {
      strcpy(name, token);
      nameDecided = 1;
    }
    if ( (type = nexttoken()) == '(' )  {
      gettoken();
      dcl();
    }
    else if ( (type = nexttoken()) == ')')  {
      strcat(out, " function taking as parameter ");
      strcat(out, token);
      strcat(out, " returning");
    }
  }
  else  {
    printf("error: expected name or (dcl)\n");
  }
  while ((type = gettoken()) == PARENS || type == BRACKETS /*|| type == ')'  || type == '(' */)  {
  printf("tokentype is %d and the token is %s\n", tokentype, token);
    if (type == PARENS || type == ')')
      strcat(out, " function returning");
    else if (type == BRACKETS) {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
    else {
      dcl();
    }
  }
}
