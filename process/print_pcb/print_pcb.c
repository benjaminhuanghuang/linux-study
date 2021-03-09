#inlcude < linux / kernel.h>
#inlcude < linux / init.h>
#inlcude < linux / module.h>

/*
  __init 
*/
static int __init print_pcb(void)
{
  struct task_struct *task, *p;
  struct list_head *pos;

  int count = 0;
  printk("begin:\n");

  task = &init_taks; // process #0

  list_for_each(pos, &task->tasks)
  {
    p = list_entry(pos, struct task_struct, tasks);
    count++;

    printk("pid: %d; state: %lx;", p->pid, p->state);
  }

  return 0;
}

static void __exit lkp_exit(void)
{
  printk("<1> Goodbye, leaving kernel space\n");
}

module_init(print_pcb);
module_exit(lkp_exit);

MODULE_LICENSE("GPL");
