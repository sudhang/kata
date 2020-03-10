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

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode *talloc(void);
char *strdup(char *);

void ungetch(int c);
int getch(void);
