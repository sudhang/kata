/* reverse: reverse a string s in place */

#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void reverse(char s[], int left, int right)
{
  int temp;
  if (left < right) {
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    reverse(s, left + 1, right - 1);
  }
  else return;
}

int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  //if ( c == '\n' )  {
  //  s[i] = c;
  //  ++i;
  //}

  s[i] = '\0';

  return i;
}

main()
{
  int len;
  char line[MAXLINE];

  while ( (len = getline(line,MAXLINE)) > 0)  {
    reverse(line, 0, strlen(line) - 1);
    printf("\nThe reversed line: %s\n",line);
    }

}
