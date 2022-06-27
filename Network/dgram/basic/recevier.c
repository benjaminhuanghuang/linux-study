/*
  Runing before sender start
  1. get socket  : socket()
  2. get address : bind()
  3. send / receive message :  recvfrom()
  4. close socket : close()
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"

int main()
{
  // 1.
  int sd = socket(AP_INET, SOCK_DGRAM, 0); // 0 is the deault protocal in AP_INET: IPPROTO_UDP

  if (sd < 0)
  {
    perror("socket() error");
    exit(1);
  }

  // 2.
  //  different protocol use different address type
  struct sockaddr_in local_address; // man 7 ip
  local_address.sin_family = AF_INET;
  local_address.sin_port = htons(atoi(ECVPORT));
  inet_pton(AF_INET, "0.0.0.0", local_address.sin_addr); // convert ip address to binary format

  if (bind(sd, (void *)&local_address, sizeof(local_address)) < 0) //
  {
    perror("bind() error");
    exit(1);
  }

  // 3.
  struct msg_st receive_buffer;
  struct sockaddr_in receive_addr;
  scocklen_t remote_addr_len = sizeof(remote_addr);
  while (1)
  {
    recvfrom(sd, &receive_buffer, sizeof(receive_buf fer), 0, (void *)&receive_addr, &remote_addr_len);
    printf(" Message from %s: %d---\n", raddr.sin_addr, raddr.sin_port);
  }

  close(sd);

  exit(0); 
}
