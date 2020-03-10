#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/* the tree node */
struct tnode  {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

/* the output array */
struct outarray {
  char *word;
  int count;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void getcounts(struct tnode *, struct outarray *, int *);
int getword(char *, int);

struct tnode *talloc(void);
char *Strdup(char *);

void ungetch(int c);
int getch(void);
void sort(struct outarray *, int);
