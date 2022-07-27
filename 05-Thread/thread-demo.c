
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

struct message
{
  int t_num;
  int i;
};

void *
hello(struct message *str)
{
  printf("child, the tid=%lu\n\n", pthread_self());

  printf("The thread_num is %d, arg.j is %d\n\n", str->t_num, str->i);

  printf("child, getpid()=%d\n\n", getpid());

  while (1)
    ;
}

int main(int argc, char *argv[])
{
  struct message test1, test2;
  pthread_t thread_id1, thread_id2;

  test1.t_num = 1;
  test1.i = 10;

  test1.t_num = 2;
  test1.i = 20;

  pthread_create(&thread_id1, NULL, hello, &test1);
  pthread_create(&thread_id2, NULL, hello, &test2);

  printf("parent, the tid=%lu\n\n", pthread_self());
  printf("parent, the getpid()=%d\n\n", getpid());

  //
  pthread_join(thread_id1, NULL);
  pthread_join(thread_id2, NULL);

  return 0;
}