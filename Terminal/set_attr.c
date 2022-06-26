#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main()
{
  struct termios new, old;

  tcgetattr(0, &old);
  tcgetattr(0, &new);

  // disable ECHO for local mode
  new.c_lflag = new.c_lflag & ~(ICANON | ECHO);
  // accept 1 char as input
  new.c_cc[VMIN] = 1;
  // 0 is stdin, 1 is stdout
  // TCSANOW : effect immediately
  tcsetattr(0, TCSANOW, &new);

  int ch;
  while (1)
  {
    ch = getchar();
    if (ch == 'Q')
    {
      // exit while loop
      break;
    }

    printf("%x ", ch);
    fflush(NULL);
  }

  // recover the old attributes
  tcsetattr(0, TCSANOW, &old);
  return 0;
}