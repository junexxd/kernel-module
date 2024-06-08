/*
    Passing command line arguments to a kernel module
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/stat.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roshan Kumar");
MODULE_DESCRIPTION("Passing command line arguments to a kernel module");

static short int v1 = 1;
static char *msg = "Hello";
static int arr[2] = { 420, 420 };
