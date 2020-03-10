/* compare two lines, printing the first line where they differ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

main()
{
  FILE *f1, *f2;
  char *s1, *s2;
  char *st;

  f1 = fopen("ex7-6.1","r");
  f2 = fopen("ex7-6.2","r");

  s1 = (char *) malloc(sizeof(char)*MAXLINE);
  s2 = (char *) malloc(sizeof(char)*MAXLINE);
  /* !: here, it is important to multiply the sizeof(char) with 'MAXLINE'
   * because otherwise, it is possible that two very adjacent addresses
   * are allocated to s1 and s2, therefore, they will overwrite each other
   */

  while(fgets(s1, MAXLINE, f1) != NULL && fgets(s2, MAXLINE, f2) != NULL) {
    if(strcmp(s1, s2) != 0)
      break;
  }

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
}
