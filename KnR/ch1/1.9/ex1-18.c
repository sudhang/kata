/* Write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 100

int getline(char s[], int len);
void stripTrailingBlanks(char s[]);

main ()
{
  int len, c, i;
  char line[MAXLINE];

  while ( (len = getline(line,MAXLINE)) > 0 ) {
    stripTrailingBlanks(line);
    if ( line[0] != '\0') {
      printf("%s\n",line);
      for ( i = 0 ; i < len ; i++ )
        line[i] = '\0';
    }
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

void stripTrailingBlanks(char s[])
{
  int i, state = OUT, last_IN = -1;

  for (i = 0 ; s[i] != '\0' ; ++i)  {
    if ( (s[i] != ' ') && (s[i] != '\t') )  {
      if (state == OUT)
        state = IN;
      last_IN = i;
    }
    else
      if (state == IN)
        state = OUT;
  }
  if (state == OUT) 
    s[last_IN + 1] = '\0';
}
