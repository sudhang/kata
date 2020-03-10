/* Reads a set of text lines and prints the longest */

#include <stdio.h>

#define MAXLINE 100   /* Maximum input line length */

int getline(char s[], int lim);
void copy(char to[], char from[]);

main ()
{
  int len, max = 0;
  char line[MAXLINE], longest[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0 ) {
    if (len > max)  {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)  {   /* At least one line */
    printf("\nThe longest line is: \n%s\n",longest);
  }

  return 0;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i = 0;

  while ( (to[i] = from[i]) != '\0' )
    i++;
}
