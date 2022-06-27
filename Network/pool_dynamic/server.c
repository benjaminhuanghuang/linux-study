#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "proto.h"

#define IPSTRSIZE 4096
#define BUFSIZE 1024
#define PROCNUM 4

static void server_loop(int sd);
static void server_jb(int sd);
