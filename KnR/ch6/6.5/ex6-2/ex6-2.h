#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/* the tree node */
struct typenode {
  char *wordtype;
  int count;
  struct typenode *left;
  struct typenode *right;
  struct wordnode *words;
};

struct wordnode {
  char *word;
  struct wordnode *next;
};

#define MAXWORD 100
struct typenode *addtree(struct typenode *, char *, int);
void treeprint(struct typenode *);
int getword(char *, int);

struct typenode *talloc(void);
char *strNdup(char *, int);

void ungetch(int c);
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */

int getch(void);
int nchars;   /* no. of chars in the prefix to consider */
