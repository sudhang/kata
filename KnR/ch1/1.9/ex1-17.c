/* Write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>

#define MIN 80
#define MAXLINE 100

int getline(char s[], int lim);
void copy(char to[], char from[]);

main ()
{
  int len;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0 )  {
    if (len > 80)
      printf("%s\n",line);
  }
}


int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  return i;
}
