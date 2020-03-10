/* Extend entab and detab to accept the shorthand 
 *    entab -m +n
 * to mean tab stops every n columns, starting at column
 * m. Choose convenient (for the user) default behaviour
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define WSPACE 0
#define BSPACE 1
#define TABSTOPS 4

int getline(char s[], int lim);
void entab(char from[], char to[], int tabstops);
void print_hardcore(char s[]);
void detab(char line[], char detabbed[], int tabstops);

main (int argc, char **argv)
{
  int c, len, tabstops;
  char line[MAXLINE], entabbed[MAXLINE], detabbed[MAXLINE];

  if (argc == 1)
    tabstops = TABSTOPS;
  else
    tabstops = atoi(argv[1]);

  while ( (len = getline(line, MAXLINE)) > 0 )  {
      entab(line, entabbed, tabstops);
      printf("The entabbed line: %s\nor: ",entabbed);
      print_hardcore(entabbed);

      detab(line, detabbed, tabstops);
      printf("The detabbed line: %s\n",detabbed);
      print_hardcore(detabbed);
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

void entab(char from[], char to[], int tabstops)
{
  int nblanks, ntabs, state = BSPACE, i, j = 0;
  nblanks = ntabs = 0;

  for ( i = 0 ; from[i] != '\0' ; ++i)  {
    if ( from[i] == ' ' ) {
      if ( state == BSPACE )
        state = WSPACE;

        ++nblanks;

      if ( nblanks == tabstops )  {
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
      if ( state == WSPACE )  { /*First char after Whitespace*/
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

      else  /*Previous Character was a "black" one*/
        to[j++] = from[i];
    }
  }

  to[j] = '\0';
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
      for (k = 0; k < tabstops; ++k)  {
        detabbed[j+k] = ' ';
      }
      j += tabstops;
    }
  }
  detabbed[j] = '\0';
}

void print_hardcore(char s[])
{
  int i;

  for (i = 0; s[i] != '\0' ; ++i) {
    if (s[i] == ' ')  
      printf("\\b");
    else if (s[i] == '\t')  
      printf("\\t");
    else  putchar(s[i]);

  }
  printf("\n");
}
