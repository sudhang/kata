#include <stdio.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *buf);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getline(char *, int);
char *alloc(int);

#define BUFSIZE 10000
static char buf[BUFSIZE];
