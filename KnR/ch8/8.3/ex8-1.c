/* BUGS: does not work with bufgetchar */

#include <fcntl.h>
#include "syscalls.h"

/* getchar: unbuffered single character input */
int Getchar(int fd)
{
  char c;
  return (read(fd, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int bufgetchar(int fd)
{
  static char buf[BUFSIZE];
  static char *bufp = buf;
  static int n = 0;

  if (n == 0) {
    /* buffer is empty */
    n = read(fd, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int putChar(int fd, int c)
{
  if (write(fd, &c, 1) != 1)
    return -1;
  else return 0;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int fd1, int fd2)
{
  int c;

  while ((c = Getchar(fd1)) != EOF)
    putChar(fd2, c);
}

/* cat: concatenate files, version 1 */
main(int argc, char *argv[])
{
  int fd;

  if (argc == 1) {
    filecopy(0, 1);
  }
  else
    while (--argc > 0)  {
      printf("argc: %d\n", argc);
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
        printf("cat: cannot open %s\n", *argv);
        return 1;
      } else  {
        filecopy(fd, 1);
        close(fd);
      }
    }
  return 0;
}
