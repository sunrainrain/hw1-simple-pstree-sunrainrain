#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <x86_64-linux-gnu/sys/types.h>
#include <netinet/in.h>
#include <x86_64-linux-gnu/sys/syscall.h>

#define AF_NETLINK PF_NETLINK
#define SOCK_RAW SOCK_RAW
#define NETLINK_USER 1
#define MAX_PAYLOAD 1024



void send_msg(char *send);


