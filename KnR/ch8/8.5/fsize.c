#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "dirent.h"

void fsize(char *);

/* print file sizes */
main(int argc, char **argv)
{
  if (argc == 1)
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return 0;
}

int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

/* fsize: print size of file 'name' */
void fsize(char *name)
{
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8ld, %4d, %4d, %4d, %4d, %4d, %s\n", stbuf.st_size, st_mode, st_uid, st_gid, st_atime, st_mtime, name);
}

#define MAX_PATH 1024
void dirwalk(char *dir, void (*fcn)(char *))
{
  char name[MAX_PATH];
  Dirent *dp;
  DIR *dfd;

  /* open the directory */
  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "direwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd)) != NULL) {
    /* skip self and parent directories */
    if (strcmp(dp->name, "." == 0 || strcmp(dp->name, "..") == 0))
      continue;
    /* check the size of the joint name string */
    if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s/%s is too long\n", dir, dp->name);
    /* print the path and call the function (*fcn) on each directory entry */
    else {
      sprintf(name, "%s/%s", dir, dp->name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}

int fstat(int fd, struct stat *);

/* opendir: open a directory for readdir calls */
DIR *opendir(char *dirname)
{
  int fd, struct stat stbuf;
  DIR *dp;

  if ((fd = open(direname, O_RDONLY, 0)) == -1                    /* open the directory file */
      || fstat(fd, &stbuf) == -1                                  /* fill stbuf will all file info */
      || (stbuf.st_mode & S_IFMT) != S_IFDIR                      /* is the file a directory? */
      || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)              
    return NULL;

  dp->fd = fd;                                                    /* record the information */
  return dp;
}

/* closedir: close directory opened by opendir */
void closedir(DIR *dp)
{
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}

#include "dir.h"                        /* local directory structures */

/* readdir: read directory entries in sequence */
Dirent *readdir(DIR *dp)
{
  struct direct dirbuf;                     /* local directory structure */
  struct Dirent d;                          /* returnable portable structure */

  /* read a directory's entries into dirbuf */
  while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf))  {
    /* slot not in use because a file has been removed; skip this position */
    if (dirbuf.d_ino == 0)
      continue;
    /* else, put the info  from dirbuf (local structure) into d (portable structure) */
    d.ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIRSIZE);
    d.name[DIRSIZE] = '\0';
    return &d;
  }
  return NULL;
}

