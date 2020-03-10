/* why does this not 
 * work? */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PAGELINES 36
#define MAXLINE 1000

int showInPage(FILE *fp)
{
  char *line;
  line = (char *) malloc(sizeof(char)*MAXLINE);
  int lnum, pcount = 1;
  char *t;
  t = line;

  while (t != NULL)  {
    lnum = PAGELINES;
    printf("Page number: %d\n", pcount);
    while (--lnum > 0 && t != NULL)  {
      if (t = fgets(line, MAXLINE, fp))
        printf("%s", line);
    }
    pcount++;
  }

  return pcount - 1;
}

main()
{
  FILE *fp;
  fp = fopen("file.txt", "r");
  printf("filename: %s\n", "file.txt");
  printf("%d pages in all\n", showInPage(fp));
}
