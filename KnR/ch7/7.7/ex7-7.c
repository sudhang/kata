/* grep: print each line of input that contains a particular "pattern" or 
 * string of characters
 */

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

/* find all lines matching pattern */
main(int argc, char *argv[])
{
  char line[MAXLINE];
  int found = 0, index, i, lnum;
  FILE *fp;

  if (argc < 3)
    printf("usage: ./grep pattern file(s)\n");
  else  {
    i = 2;
    while (i < argc) {
      fp = fopen(argv[i], "r");
      lnum = 1;
      while ( fgets(line, MAXLINE, fp) != NULL )  {
        if ( (index = strindex(line, argv[1])) >= 0 ) {
          printf("%s:\t%5d:%3d: %s", argv[i], lnum, index, line);
          found++;
        }
        lnum++;
      }
      i++;
    }
  }
  return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
