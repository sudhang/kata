#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int nexttoken(void);
int tokentype;                  /* type of last token */
int nameDecided;                   /* 0: name decided 1: name not decided */
char token[MAXTOKEN];           /* last token string */
int prevTokenExists;            /* 0: doesn't exist, 1: exists */
char name[MAXTOKEN];            /* identifier name */
char datatype[MAXTOKEN];        /* data type = char, int, etc. */
char out[1000];                 /* output string */

int getch(void);
void ungetch(int);
