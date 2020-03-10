#include "tbl.h"

/* getline: get line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')  {
    s[i++] = c;
  }
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

main()
{
  char *kw, *rep, *line, *word;
  rep = (char *)malloc(sizeof(char));
  kw = (char *)malloc(sizeof(char));
  line = (char *)malloc(sizeof(char));
  word = (char *)malloc(sizeof(char));
  struct nlist *np;
  while(getLine(line, MAXLINE) > 1)  {
    sscanf(line, "#define %s %s", kw, rep);
    install(kw, rep);
  }
  while(getword(word, MAXWORD) > 1) {
    if((np = lookup(word)) != NULL) {
      printf("%s ", np->defn);
    }
    else  {
      printf("%s ", word);
    }
  }
}
