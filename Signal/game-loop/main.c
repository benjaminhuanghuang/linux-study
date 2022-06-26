
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
/*
unsigned int alarm(unsigned int seconds)

After seconds have elapsed since requesting the alarm() function, the SIGALRM signal is generated
*/
void alarm_handler(int s){
  alram(1);
  printf("Get SIGALARM\n");
}


int main() {
  // register
  signal(SIGALRM, alarm_handler);   

  //
  alram(1);
  
  while(1){
    // printf("while(1)\n");
    // sleep(1);
    int ch = getchar();
    printf("ch = %x\n", ch);
  }
  return 0;
}


