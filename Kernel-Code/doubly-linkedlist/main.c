#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy

#include "list.h"

#define NAMESIZE 32

struct scrore_st
{
  int id;
  char name[NAMESIZE];
  int math;
  int chinese;
};

int main()
{
  struct scrore_st *data_ptr;
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

    list_insert(&data_ptr->node, &head);

    list_for_each(curr, &head)
    {
    }
  }

  exit(0);
}