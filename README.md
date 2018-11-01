# HW1-simple-pstree
It's a file that understand how to transfer the information between the kernel and the user space processes.

## **simple-pstree** ##
In this class, there is a main function and a subroutine.
- int main(int argc, const char*argv[]){}
- void user_send_msg(char *send){}

we use the netlink socket function to deliver message to the kernel.
this is a socket that we create:
+ sock = socket(AF_NETLINK, SOCK_RAW, 1);



## **ksimple-pstree** ##
In this class,there are some functions that search the chidren, siblings and parents in the process tree and the pid of these processes.


when we receive the message from the user space, we create a netlink socket in this class.
+ nl_sk = netlink_kernel_create(1, nl_wakeup);

Using these functions to find the pid and find the sibling, children and parent!
 1. After excuting the **find_get_pid()**, the process descriptor field *count* will become two.

    > pid_struct = find_get_pid(pid);

 2. The **pid_task()** function gets the task descriptor information of the task. This task is in the usage list of the process pid, andthe subscript of the starting element of the searched list is the value of the parameter type.

    > T = pid_task(pid_struct,PIDTYPE_PID);

 3. It will search all the process when the pointer points the position from the next of the head via **list_fot_entry()** function.

    > list_for_each(list, &T->children){}

