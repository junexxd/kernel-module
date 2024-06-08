/*
    Passing command line arguments to a kernel module
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/stat.h>
#include <linux/printk.h>
#include "cla.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roshan Kumar");
MODULE_DESCRIPTION("Passing command line arguments to a kernel module");

static short int v1 = 1;
static char *msg = "Hello";
static int arr[2] = { 420, 420 };
static int arr_argc = 0;

/*
    module_param(name, type, permission)
    name: name of the variable
    type: data type of the variable
    permission: permission bits
*/

module_param(v1, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(v1, "An short integer");
module_param(msg, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string"); 

/*
    module_param_array(name, type, nump, permission)
    name: name of the variable
    type: data type of the variable
    nump: pointer to the variable that will store the number of elements
    permission: permission bits

*/

module_param_array(arr, int, &arr_argc, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

static int __init mod_init(void)
{
    int i;

    printk("Short integer: %hd\n", v1);
    printk("Character string: %s\n", msg);
    printk("Number of elements in the array: %d\n", arr_argc);


    for (i = 0; i < ARRAY_SIZE(arr); i++)
    {
        printk("Array element %d: %d\n", i, arr[i]);
    }

    return 0;
}

static void __exit mod_exit(void)
{
    printk("Exiting the module\n");
}

module_init(mod_init);
module_exit(mod_exit);