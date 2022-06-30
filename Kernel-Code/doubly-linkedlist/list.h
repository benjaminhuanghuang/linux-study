#ifndef LINUXLIST_H
#define LINUXLIST_H
struct list_head
{
  struct list_head *prev;
  struct list_head *next;
};

// 生成struct的两个字段,都指向它自己
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

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 *  ptr: curr
 *  type: struct score_st
 *  member: node
 */
#define container_of(ptr, type, member) \
  ({ (type *)((char *)ptr - offsetof(type, member)); })

/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 */
#define list_entry(ptr, type, member) \
  container_of(ptr, type, member)
/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void
__list_add(struct list_head *new,
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
