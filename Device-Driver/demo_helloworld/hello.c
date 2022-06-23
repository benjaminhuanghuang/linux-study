#include <linux/init.h>
#include <linux/module.h>

static int hello_init(void) {
  printk(KENR_ALERT "Hello!");
  return 0;
}


static void hello_exit(void) {
  printk(KENR_ALERT "Bye!");
  return 0;
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ben")
