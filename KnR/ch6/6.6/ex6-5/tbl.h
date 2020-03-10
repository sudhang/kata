#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
#define HASHSIZE 101
#define MAXWORD 100

struct nlist  {           /* table entry */
  struct nlist *next;     
  char *name;             /* keyword */
  char *defn;             /* replacement */
};

static struct nlist *hashtab[HASHSIZE];   /* pointer table */

unsigned hash(char *s);
char *Strdup(char *);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
