#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode  {
  char *word;
  int match;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *p);
int getword(char *, int);

/* make a duplicate of s */
char *strdup(char *s)
{
  char *p;
  p = (char *) malloc(strlen(s) + 1);   /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

main(int argc, char *argv[])
{
  struct tnode *root;
  char word[MAXWORD];
  int found = NO, num;
  num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 3;
  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0]) && strlen(word) >= num)
      root = addtreex(root, word, num, &found);
    found = NO;
  }
  treexprint(root);
  return 0;
}

int compare(char *, struct tnode *, int, int *);

struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
  int cond;
  if(p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->match = *found;
    p->left = p->right = NULL;
  } else if ((cond = compare(w, p, num, found)) < 0)
    p->left = addtreex(p->left, w, num, found);
  else if (cond > 0)
    p->right = addtreex(p->right, w, num, found);
  return p;
}

int compare(char *s, struct tnode *p, int num, int *found)
{
  int i;
  char *t = p->word;

  for (i = 0; *s == *t; i++, s++, t++)
    if (*s == '\0')
      return 0;
  if (i >= num) {
    *found = YES;
    p->match = YES;
  }
  return *s - *t;
}

void treexprint(struct tnode *p)
{
  if (p != NULL)  {
    treexprint(p->left);
    if (p->match)
      printf("%s\n", p->word);
    treexprint(p->right);
  }
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* getword: get next word or character from the input */
int getword(char *word, int lim)
{
  int c;
  char *w = word;

  while (isspace(c = getch()))                /* ignore leading blanks and underscores */
    ;

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c))  {
    if (c == '/')   {
      if ( (c = getch()) == '*' ) {                       /* it is the start of a comment */
        while ( (c = getch()) )                           /* skip the comment string      */
          if (c == '*' && getch() == '/')                 /* end of comment string        */
            break;
      }
      else ungetch(c);
    }
    else if (c == '"')  {                                 /* it is the start of a string constant */
      while ((c = getch()) != '"')                        /* skip string constant                 */
        ;
    }
    else if (c == '_')  {
      while (isalnum(getch()))
          ;
    }
    else if ( c == '#' )  {
      while ( getch() != '\n' )
        ;
    }
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
