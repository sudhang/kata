#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define CODE 0
#define COMMENT 1

int getline(char s[], int lim);
void uncomment(char from[], int len);

main()
{
  int c, len;
  char line[MAXLINE];

  while ( (len = getline(line, MAXLINE)) )  {
    printf("The uncommented code: \n");
    uncomment(line, len);
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

void uncomment(char from[], int len)
{
  int i, j, state = CODE;

  for ( i = 0, j = 0; i < len ; ++i, ++j )  {
    if ( ( state == CODE ) )  {
      if ( ( from[i] == '/' ) && ( from[i+1] == '*' ) )  {  //An old-style comment was encountered
        state = COMMENT;
        ++i;
      }
      else {
        putchar(from[i]);
      }
    }

    else if ( ( from[i] == '*' ) && ( from[i+1] == '/' ) )  { //Comment ended here
      state = CODE;
      ++i;
    }
  }
}
