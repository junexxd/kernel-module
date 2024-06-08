#include <linux/module.h>
#include <linux/init.h>
#include <linux/printk.h>

/* META INFORMATION */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roshan Kumar");
MODULE_DESCRIPTION("BASIC LKM");

/** 
 * @brief This function is called, when the module is loaded in the kernel
 */

static int data_1 __initdata = 10;

static int __init ModuleInit(void) {
	printk("Module loaded into the kernel\n");
	printk("The value of data_1 is %d\n", data_1);
	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */

static void __exit ModuleExit(void) {
	printk("Module removed from kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
