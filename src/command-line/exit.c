#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include "command-line.h"

static void __exit mod_exit(void)
{
    printk("Exiting the module\n");
}

MODULE_LICENSE("GPL");