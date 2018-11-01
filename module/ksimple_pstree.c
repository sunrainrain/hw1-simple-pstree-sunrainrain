#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>
MODULE_DESCRIPTION("Hello_world");
MODULE_LICENSE("GPL");

struct task_struct* T;
struct pid *pid_struct;


struct element {
    struct list_head list;
    int data;
    float more_data;
};

static int pid_init(void)
{
    printk(KERN_INFO "Hi!");
    struct task_struct *task; 
    struct list_head *list;
    pid_t pid = 1; 
    pid_struct = find_get_pid(pid);
   
        T = pid_task(pid_struct,PIDTYPE_PID);
    
        list_for_each(list, &T->children) { 
            task = list_entry(list, struct task_struct, sibling); /* task now points to one of current’s children */ 
            printk("parent: %d %s ", task->pid, task->comm);
        
	} 
    
    
 return 0;
}

static void pid_exit(void){
  printk(KERN_INFO "Bye !\n");
}


MODULE_LICENSE("GPL");
module_init(pid_init);
module_exit(pid_exit);
