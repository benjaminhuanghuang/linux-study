#ifndef LINUXLIST_H
#define LINUXLIST_H

// 把一个变量有两个字段,都指向它自己
#define LIST_HEAD_INIT(name) \
  {                          \
    &(name), &(name)         \
  }

#define LIST_HEAD(name) \
  struct list_head name = LIST_HEAD_INIT(name)

/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop cursor.
 * @head:	the head for your list.
 */
#define list_for_each(pos, head) \
  for (pos = (head)->next; pos != head; pos = pos->next)

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
  next->prev = new;
  new->next = next;
  new->prev = prev;
  prev->next = new;
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
  // put new between head and head->next
  __list_add(new, head, head->next);
}

#endif
