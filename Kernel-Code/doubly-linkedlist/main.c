#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy

#include "list.h"

#define NAMESIZE 32

struct score_st
{
  int id;
  char name[NAMESIZE];
  struct list_head node; // prev & next
  int math;
  int chinese;
};

static void print_s(struct score_st *d)
{
  printf("%d %s %d %d \n", d->id, d->name, d->math, d->chinese);
}

int main()
{
  struct score_st *data_ptr;
  struct list_head *curr;

  LIST_HEAD(head);

  for (int i = 0; i < 3; i++)
  {
    data_ptr = malloc(sizeof(*data_ptr));
    if (data_ptr == NULL)
    {
      exit(1);
    }
    data_ptr->id = i;
    // can not use : tmp.name = "test";
    snprintf(data_ptr->name, NAMESIZE, "stu%d", i);
    data_ptr->math = rand() % 100;
    data_ptr->chinese = rand() % 100;

    list_add(&data_ptr->node, &head);

    list_for_each(curr, &head)
    {
      // offset between 0 to struct score_st->node)
      data_ptr = list_entry(curr, struct score_st, node);
      print_s(data_ptr);
    }
  }

  exit(0);
}