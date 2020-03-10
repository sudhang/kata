/* Revise the main routine of longestLine.c to accept arbitrarily long input lines */


#include <stdio.h>

#define MAXLINE 10   /* Maximum input line length */

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
    printf("\nThe longest line is: \n%s\nIt's length is: %d\n",longest,max);
  }

  return 0;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    if (i < lim)
      s[i] = c;
  if ( c == '\n' )  {
    i++;
    if (i < lim)
      s[i] = c;
  }

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i = 0;

  while ( (to[i] = from[i]) != '\0' )
    i++;
}
