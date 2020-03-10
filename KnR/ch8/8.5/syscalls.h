#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>

#define NULL 0
#define EOF (-1)
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

typedef struct _iobuf  {
  int cnt;      /* characters left */
  char *ptr;    /* next Character position */
  char *base;   /* location of the buffer */
  int flag;     /* mode of file access */
  int fd;       /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
  _READ  = 01,      /* file open for reading */
  _WRITE = 02,      /* file open for writing */
  _UNBUF = 04,      /* file is unbuffered */
  _EOF   = 010,     /* EOF has occurred on this file */
  _ERR   = 020      /* erro occurred on this file */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);
