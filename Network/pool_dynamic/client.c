#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"

int main(int argc, char *argv[]){
  int sd;
  struct sockaddr_in raddr;
  long long stamp;
  FILE *fp;

  if(argc < 2) {
    
  }
}