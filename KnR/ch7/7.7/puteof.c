#include<stdio.h>

main()
{
  FILE *fp;
  fp = fopen("file.txt", "a+");
  fputc(EOF, fp);
  fclose(fp);
}
