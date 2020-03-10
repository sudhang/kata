#include <stdarg.h>
#include <stdio.h>  
#include <stdlib.h>
#include <fcntl.h>

#define BUFSIZE 1024
#define OPEN_MAX 20

/* error: print an error messge and die */
void error(char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  fprintf(stderr, "error: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}

typedef long Align;         /* for alignment to a long boundary */
union header  {             /* block header */
  struct  {
    union header *ptr;      /* next block on the free list */
    unsigned size;
  } s;
  Align x;
};

typedef union header Header;
