/* Extend atof to handle scientific notation of the form
 *      123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent
 */

#include <stdio.h>

#define MAXLINE 100
#define BASE 10.0

int atoi(char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); ++i)   //Skip whitespace
    ;

  sign = (s[i] == '-') ? -1 : 1;    

  if (s[i] == '+' || s[i] == '-') //Skip sign
    ++i;

  for (n = 0; isdigit(s[i]); ++i)
    n = 10*n + (s[i] - '0');

  return sign*n;
}

double atof(char s[])
{
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)       //Skip whitespace
    ;

  sign = (s[i] == '-') ? -1:1;

  if (s[i] == '+' || s[i] == '-')       //Skip sign
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val/power;
}

double atofX(char s[])
{
  char to[MAXLINE];
  int i, j = 0, sign, exponent, power;
  double val, multiplicand = 1.0;

  for (i = 0; s[i] != 'e' && s[i] != 'E' && s[i] != '\0'; i++)
    to[j++] = s[i];

  to[j] = '\0';

  val = atof(to);

  if (s[i] == 'e' || s[i] == 'E')   {
    sign = (s[++i] == '-') ? -1:1;        //Determine sign from the next character

    j = 0;

    for (; s[i] != '\0'; i++) 
      to[j++] = s[i];

    to[j] = '\0';

    exponent = atoi(to);
    if (exponent > 0)
      for (i = 0; i < exponent; ++i)
        multiplicand *= BASE;
    else
      for (i = 0; i < -1*exponent; ++i)
        multiplicand /= BASE;
  }

  return val * ( multiplicand );
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  //if (c == '\n')
  //  s[i++] = c;
  s[i] = '\0';
  return i;
}

main()
{
  char line[MAXLINE];

  while ( getline(line, MAXLINE) > 0) {
    printf("The floating point is %lf\n", atofX(line));
  }
}
