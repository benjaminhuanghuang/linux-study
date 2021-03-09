

linux-2.6.0/include/linux/list.h



```
  struct hlist_head{
    struct hlist_node *first;
  }

  struct hlist_node{
    struct hlist_node *next, **pprev;
  }

  #define HLIST_HEAD_INIT { .first = NULL }

  #define HLIST_HEAD(name) struct hlist_head name = {  .first = NULL }
  
  #define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
  
  static inline void INIT_HLIST_NODE(struct hlist_node *h)
  {
    h->next = NULL;
    h->pprev = NULL;
  }
```

