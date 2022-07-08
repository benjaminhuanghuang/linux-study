#include <stdio.h>
/*
  coopy from stdin to stdout
*/
int main()
{
  int c;
  while ((c = getchar()) != EOF)
  {
    putchar(c);
  }
}