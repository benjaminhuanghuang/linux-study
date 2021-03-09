#inlcude <linux/kernel.h>
#inlcude <linux/init.h>
#inlcude <linux/module.h>

/*
  __init 
*/
static int __init lkp_init(void){
  printk("<1> Hello from kernel space\n");
  return 0;
}


static void  __exit lkp_exit(void){
  printk("<1> Goodbye, leaving kernel space\n");
}

module_init(lkp_init);
module_exit(lkp_exit);

MODULE_LICENSE("GPL");






