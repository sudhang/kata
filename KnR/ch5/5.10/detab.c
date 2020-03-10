/* Replaces tabs in the input with the proper number of blanks to the next tab stop */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int getline(char s[], int len);
void detab(char line[], char detabbed[], int tabstops);
void print_hardcore(char s[]);

main (int argc, char **argv)
{
  int len, tabstops = atoi(argv[1]);
  char line[MAXLINE],detabbed[MAXLINE];

  while ( (len = getline(line,MAXLINE)) > 0 ) {
    detab(line,detabbed, tabstops);
    printf("The detabbed line: %s\nor: ",detabbed);
    /*print_hardcore(detabbed);*/
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

void detab(char line[], char detabbed[], int tabstops)
{
  int i,j = 0,k;

  for (i = 0 ; line[i] != '\0' ; ++i )  {
    if (line[i] != '\t')  {
      detabbed[j] = line[i];
      j++;
    }
    else {
      for (k = 0; k < tabstops; ++k) {
        detabbed[j+k] = ' ';
      }
      j += tabstops;
    }
  }
}

void print_hardcore(char s[])
{
  int i;

  for (i = 0; s[i] != '\0' ; ++i) {
    if (s[i] == ' ')
      printf("\\b");
    else if (s[i] == '\t')
      printf("\\t");
    else
      putchar(s[i]);
  }
  printf("\n");
}
