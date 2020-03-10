/* header file for keyword counting program */
#include <stdio.h>

struct key {
  char *word;
  int count;
};

#define NKEYS (sizeof keytab / sizeof keytab[0])
int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
int getch(void);
void ungetch(int);
