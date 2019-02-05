/*
q1.c 
Linux Kernal Module for Listing Tasks
by Mathew Walker
Compile with Makefile
Load with sudo insmod q1.ko
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

struct task_struct *task;


/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module q1\n");
       for_each_process(task){
	  printk("Task: %s (pid = %d)\n",task->comm, task_pid_nr(task));
       }
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}



/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
