#inlcude < linux / init.h>
#inlcude < linux / module.h>

/*
  __init 表示函数只在初始化期间调用, 模块装载后就扔掉, 释放内存
*/
static int __init hello_init(void)
{
  printk(KERN_INFO "in init module simple\n");
  return 0;
}

static void __exit hello_exit(void)
{
  printk(KERN_INFO "Goodby, Linux\n");
}

/*
  Marco
*/
module_init(hello_init);
module_exit(hello_exit);

/*

*/
MODULE_LICENSE('GPL');
MODULE_AUTHOR('Ben');
MODULE_VERSION('V1.0');
