/* Replace strings of blanks by the minimum number of tabs and blanks to achieve the same spacing */

#include <stdio.h>

#define MAXLINE 100
#define WSPACE 0
#define BSPACE 1
#define TABSTOPS 4

int getline(char s[], int lim);
void entab(char from[], char to[]);
void print_hardcore(char s[]);

main ()
{
  int c, len;
  char line[MAXLINE], entabbed[MAXLINE];

  while ( (len = getline(line, MAXLINE)) > 0 )  {
      entab(line, entabbed);
      printf("The entabbed line: %s\nor: ",entabbed);
      print_hardcore(entabbed);
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

void entab(char from[], char to[])
{
  int nblanks, ntabs, state = BSPACE, i, j = 0;
  nblanks = ntabs = 0;

  for ( i = 0 ; from[i] != '\0' ; ++i)  {
    if ( from[i] == ' ' ) {
      if ( state == BSPACE )
        state = WSPACE;

        ++nblanks;

      if ( nblanks == TABSTOPS )  {
        ++ntabs;
        nblanks = 0;
      }

    }

    else if ( from[i] == '\t' )  {
      if ( state == BSPACE )
        state = WSPACE;

      ++ntabs;
    }

    else  {
      if ( state == WSPACE )  { // First char after Whitespace
        state = BSPACE;

        while (ntabs > 0) {
          to[j++] = '\t';
          --ntabs;
        }

        while (nblanks > 0) {
          to[j++] = ' ';
          --nblanks;
        }
      to[j++] = from[i];
      }

      else  // Previous Character was a "black" one
        to[j++] = from[i];
    }
  }

  to[j] = '\0';
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
