#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLINE 100
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort1(void *lineptr[], int left, int right, int(*comp)(const void *, const void *));
int numcmp(const char*, const char*);

int getline(char *, int);
char *alloc(int);

int reverse;
