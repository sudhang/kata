#include <fcntl.h>
#include "syscalls2.h"

#define PERMS 0666

/* fopen: open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
  int fd;
  FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    if ((fp->flag._READ && fp->flag._WRITE) == 0)
      break;        /* found free slot */
  if(fp >= _iob + OPEN_MAX)
    return NULL;    /* no free slots */

  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a')  {
    if((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);         /* seek to end */
  } else
    fd = open(name, O_RDONLY, 0);
  if (fd == -1)
    return NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  (*mode == 'r') ? fp->flag._READ = 1 : fp->flag._WRITE = 1;
  return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
  int bufsize;

  /* check if the file has been opened for reading without errors */
  if ((fp->flag._READ || fp->flag._EOF || fp->flag._ERR ))
      return EOF;

  bufsize = (fp->flag._UNBUF) ? 1 : BUFSIZE;

  /* if the buffer has not been created yet, do so */
  if(fp->base == NULL)    /* no buffer yet */
    if((fp->base = (char *) malloc(bufsize)) == NULL)
      return EOF;        /* can't get buffer */

  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);

  /* check for errors in read() */
  if(--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag._EOF;
    else
      fp->flag._ERR;
    fp->cnt = 0;
    return EOF;
  }

  return (unsigned char) *fp->ptr++;
}

/* _flushbuf: write the contents of the buffer into the file */
int _flushbuf(FILE *fp)
{
  int bufsize ;

  /* check if the file has been opened for writing, without errors */
  if ((fp->flag._WRITE || fp->flag._EOF || fp->flag._ERR ))
      return EOF;

  /* even if the buffer has not been completely filled, we must allow flushing */
  bufsize = (fp->flag._UNBUF) ? 1 : BUFSIZE - fp->cnt;

  /* if the buffer has not been created yet, return with error */
  if(fp->base == NULL)    /* no buffer yet */
    return EOF;

  fp->ptr = fp->base;
  fp->cnt += write(fp->fd, fp->ptr, bufsize);    /* cnt = cnt + BUFSIZE - cnt */

  /* check for errors in write() */
  if(--fp->cnt != BUFSIZE) {
    fp->flag._ERR
    fp->cnt = 0;
    return EOF;
  }

  --fp->cnt;
  return (*(fp->ptr)++ = x);
}

/* fflush: write any buffered but unwritten data on output streams.  if argument is null, flush all open output streams */
int fflush(FILE *stream)
{
  if (stream)
    if (_flushbuf(stream) != EOF)
      return 0;
    else return EOF;
  else                                            /* we now have to flush all open streams */
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)   /* walk through the opened streams */
      if ((fp->flags._WRITE)   {     /* opened for writing */
        if (fp->cnt <= BUFSIZE)  {                /* something is in the buffer */
          if (_flushbuf(stream) != EOF) {
            _flushbuf(fp);
            return 0;
          }
          else return EOF;
        }
        else return EOF;
      }
  return EOF;
}

/* fclose: flush any unwritten data, discard any unread buffered input, free any automatically allocated buffer, then close the stream. */
int fclose(FILE *stream)
{
  int ret;
  /* flush any unwritten data */
  if (fp->flag._WRITE)
    if (_flushbuf(stream) == EOF)
      return EOF;

  /* free the buffers, whether input or output */
  if (fp->base)
    free(fp->base);

  close(fp->fd);
  free(fp);
}
