/* Write a function escape(s, t) that converts characters like newline and tab to
 * visible escape sequences like \n and \t as it copies the string t to s. Use a switch 
 * Write a function for the other direction as well, converting escape sequences to characters
 */

#include <stdio.h>

#define MAXLINE 100

void escape(char s[], char t[])
{
  int i, j = 0;

  for (i = 0; s[i] != '\0'; ++i)  {

    switch (s[i]) {
      case '\n': 
        t[j++] = '\\';
        t[j++] = 'n';
        break;
      case '\t': 
        t[j++] = '\\';
        t[j++] = 't';
        break;
      case '\b': 
        t[j++] = '\\';
        t[j++] = 'b';
        break;
      default  :
        t[j++] = s[i];
        break;
    }

  }
  t[j] = '\0';
}

void descape(char s[], char t[])
{
  int i, j = 0;

  for (i = 0; s[i] != '\0'; ++i)  {

    switch (s[i]) {
      case '\\':
        switch (s[i+1]) {
          case 'n':       //Newline
            t[j++] = '\n';
            j++;
            break;
          case 't':       //Tab
            t[j++] = '\t';
            j++;
            break;
          case 'b':       //Backspace
            t[j++] = '\b';
            j++;
            break;
          default:
            t[j++] = s[i];
        }
        break;
      default:
        t[j++] = s[i];
        break;
    }
  }
  t[j] = '\0';
}


int getline(char s[], int lim)
{
  int c, i;

  for ( i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && ( c != '\n' ) ; ++i )
    s[i] = c;
  if ( c == '\n' )  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

main ()
{
 int len;
 char s[MAXLINE], t[MAXLINE];

 while ( (len = getline(s, MAXLINE)) > 0) {
   escape(s,t);
   printf("\nThe new string after escaping is: %s\n",t);
   descape(s,t);
   printf("\nThe above string after de-escaping is: %s\n",t);
 }
}
