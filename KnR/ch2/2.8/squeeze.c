/* squeeze.c: delete all c from s */

#include <stdio.h>

#define MAXLINE 100
#define CHARACTER 'c'

void squeeze(char s[], char c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] != c)
      s[j++] = s[i];
  }

  s[j] = '\0';
}

main ()
{
  int len;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE) ) > 0 )   {
    squeeze(line,'c');
    printf("The new line is: %s", line);
  }

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
