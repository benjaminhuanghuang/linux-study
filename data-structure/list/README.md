include/linux/list.h
```
  struct list_head {
    struct list_head *next, *prev
  }

  #define LIST_HEAD_INIT(name) {&(name), &{name}}


  #define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)


  // inster
  // static: function only can be used in current file
  static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next){
    next->prev = new;
    next->next = new;
    new->prev = prev;
    prev->naxt = new;
  }

  // for each
  #define list_for_each(pos, head) \
    for (pos =(head)->next; pos!=(head); pos=pos->next)

  // get node address
  #define list_entry(prt, type, number) \
    ((type *))((char *))(ptr)-(unsigned long)(&((type *)0)->member)

  
```


## usage
```
  struct my_list {
    void *my_data;
    struct list_head list;
  }
```