#ifndef PROTO_H
#define PROTO_H

#define RCVPORT  "1989"
#define NAMESIZE 11

struct msg_str
{
  uint8_t name[NAMESIZE];
  uint32_t math;
  uint32_t chinese;
}__attribute__((packed));    // don't allign fields




#endif /* PROTO_H