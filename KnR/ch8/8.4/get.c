#include "syscalls.h"

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
  if (lseek(fd, pos, 0) >= 0)   /* get to pos */
    return read(fd, buf, n);
  else return -1;
}

main()
{
  int n = 12, pos = 10000, i;
  char *buf;
  buf = (char *) malloc(sizeof(char)*n);
  int fd = open("in", O_RDONLY, 0);
  get(fd, pos, buf, n);
  printf("string: %s\n\n", buf);
  for (i = 0; i < n; i++)
    printf("buf[%d]: %d\n", i, buf[i]);
}
