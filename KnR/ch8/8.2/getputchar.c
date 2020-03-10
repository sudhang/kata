#include "syscalls.h"

/* getchar: unbuffered single character input */
int getchar(void)
{
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int putchar(int c)
{
  if (write(1, &c, 1) != 1)
    return -1;
  else return 0;
}

int bufgetchar(void)
{
  static char buf[BUFSIZE];
  static char *bufp = buf;
  static int n = 0;

  if (n == 0) {
    /* buffer is empty */
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

main()
{
 char c;
 while((c = bufgetchar()) != EOF)
   putchar(c);
}
