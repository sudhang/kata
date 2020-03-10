/* strcat: concatenate t to end of s; s must be big enough */

#include <stdio.h>

#define MAXLINE 100

void strcat(char s[], char t[])
{
  int i, j;

  i = j = 0;

  while (s[i] != '\0')
    i++;

  while ((s[i++] = t[j++]) != '\0')
    ;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

main ()
{
  int len;
  char line1[MAXLINE], line2[MAXLINE];

  while ( (len = getline(line1, MAXLINE)) > 0 )  {
    printf("\nEnter the other line: ");
    getline(line2, MAXLINE);

    strcat(line1, line2);

    printf("\nThe concatenated string is: %s", line1);
  }
}
