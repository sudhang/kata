/* grep: print each line of input that contains a particular "pattern" or 
 * string of characters
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

/* find all lines matching pattern */
main(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, found = 0, except = 0, number = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])    /* *++argv[0] == *++(argv[0]); it gives the next character of the current word */
      switch (c)  {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("grep: illegal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }
  if (argc != 1)
    printf("Usage: find -x -n pattern\n");
  else
    while (getline(line, MAXLINE) > 0)  {
      lineno++;
      if((strstr(line, *argv) != NULL) != except) {
        if (number)
          printf("%ld:", lineno);
        printf("%s\n", line);
        found++;
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
