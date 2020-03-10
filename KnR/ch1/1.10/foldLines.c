#include <stdio.h>

#define MAXLINE 100
#define N 10

int getline(char s[], int lim);
void foldLine(char from[], int len, char to[]);

main()
{
  int len;

  char line[MAXLINE], folded[MAXLINE];

  while ( (len = getline(line, MAXLINE)) >0 ) {
    foldLine(line,len,folded);
    printf("The folded line: %s\n",folded);
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

void foldLine(char from[], int len, char to[])
{
  int nfolds = len/N, i, j;

  for (i = 0, j = 0 ; i < len ; ++i, ++j)  {
    if ( (i%N == 0) && (i != 0) ) 
      to[j++] = '\n';

    to[j] = from[i];
  }
}
