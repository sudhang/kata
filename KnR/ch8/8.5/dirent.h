#define NAME_MAX 14           /* longest filename component */

typedef struct  {             /* portable directory entry structure */
  long ino;                   /* file descriptor for directory */
  char name[NAME_MAX + 1];    /* name + '\0' terminator */
} Dirent;

typedef struct  {             /* minimal DIR: no buffering, etc. */
  int fd;                     /* inode number */
  Dirent d;                   /* the directory entry */
} DIR;
