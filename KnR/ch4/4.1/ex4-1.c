/* Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ou";
int reversed = 0;

/* find all lines matching pattern */
main()
{
  char line[MAXLINE];
  int found = 0, index;

  while ( getline(line, MAXLINE) > 0 )  {
    if ( (index = strrindex(line, pattern)) >= 0 ) {
      printf("%s:\tindex = %d\n", line, index);
      found++;
    }
  }
  return found;
}

void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i<j ; ++i , --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  //if (c == '\n')
  //  s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strrindex: return index of rightmost occurrence of t in s, -1 if none */
int strrindex(char s[], char t[])
{
  int i, j, k;

  if ( !reversed )  {
    reverse(t);
    reversed = 1;
  }

  for (i = strlen(s) - 1; i >= 0; i--) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j--, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return (i - strlen(t) + 2);
  }
  return -1;
}
