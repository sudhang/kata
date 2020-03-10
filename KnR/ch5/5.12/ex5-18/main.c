#include "dcl.h"
main()    /* convert declaration to words */
{
  while (gettoken() != EOF) {     /* 1st token on line */
    if (tokentype == NAME)
      strcpy(datatype, token);      /* is the datatype */
    else  {
      printf("no datatype specified\n");
      return -1;
    }
    out[0] = '\0';
    dcl();    /* parse rest of line */
    if ( tokentype != '\n' )
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}
