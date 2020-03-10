#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define YES 1
#define NO 0
#define MAXWORD 100
#define MAXLINES 1000

/* the tree node */
struct tnode  {
  char *word;
  int count;
  int lines[MAXLINES];
  struct tnode *left;
  struct tnode *right;
};

char *Strdup(char *);
struct tnode *addtree(struct tnode *, char *, int lnum);
void treeprint(struct tnode *);
int getword(char *, int, int *);

struct tnode *talloc(void);

void ungetch(int c);
int getch(void);
