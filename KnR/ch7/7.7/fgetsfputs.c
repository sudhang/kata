#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

/* fgets: get at most n chars from iop */
char *Fgets(char *s, int n, FILE *iop)
{
  char c;
  char *cs;

  cs = s;

  while (--n > 0 && (c = getc(iop)) != EOF)
    if ((*cs++ = c) == '\n') {
      break;
    }
   

  *cs = '\0';
  return  (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int Fputs(char *s, FILE *iop)
{
  int c;

  while (c = *s++)
    putc(c, iop);
  return ferror(iop) ? EOF : 0;
}

/* getline: read a line, return length */
int getline(char *line, int max)
{
  if (fgets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}

main()
{
  FILE *infile, *outfile;
  infile = fopen("fgetsfputs.in","r");
  outfile = fopen("fgetsfputs.out","w");

  int i;
  char *tmp;
  tmp = (char *) malloc(sizeof(char));
  printf("first 10 lines of input fgetsfputs.in : \n");

  for (i = 0; i < 5; i++) {
    printf("line %d: ", i);
    Fgets(tmp, MAXLINE, infile);
    printf("%s\n", tmp);          /*fgets removes terminating newline*/ 
  }

  tmp = "holy monkey\n";
  printf("replacing the first 5 lines of fgetsfputs.out with \"holy monkey\"\n");
  for (i = 0; i < 5; i++)
    Fputs(tmp, outfile);
}
