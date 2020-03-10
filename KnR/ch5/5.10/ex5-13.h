#include <stdio.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define DEFLINES 10

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void tail(char *lineptr[],int totalLines, int linesToShow);

int getline(char *, int);
char *alloc(int);

