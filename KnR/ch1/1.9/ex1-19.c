/* Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input 
 * a line at a time */

#include <stdio.h>

#define MAXLINE 100

void reverse(char orig[], char reversed[]);
int getline(char s[], int lim);

main ()
{
  int len;
  char line[MAXLINE], revline[MAXLINE];

  while ( (len = getline(line,MAXLINE)) > 0 ) {
    reverse(line, revline);
    printf("The reversed line: %s\n",revline);
  } 
}

void reverse(char orig[], char reversed[])
{
  int i, j = 0;

  for( i = 0 ; orig[i] != '\0' ; ++i)
    ;

  while ( i >= 0 )  {
    --i;
    reversed[j] = orig[i];
    ++j;
  }
  reversed[j] = '\0';
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
