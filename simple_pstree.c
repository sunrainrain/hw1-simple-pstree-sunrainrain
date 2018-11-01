#include "simple_pstree.h"



int main(int argc, const char*argv[])
{
    char simple_pstre[20];
    char c[10], s[10], p[10];
    
    if(argc == 1){
        strcpy(simple_pstre, argv[0]);
        user_send_msg(simple_pstre);
    }
    else if(argc == 2){
        strcpy(simple_pstre, argv[0]);
        user_send_msg(simple_pstre);

        switch(argv[1][1]){
            case 'c':
                strcpy(c, argv[1]);
                user_send_msg(c);
                break;
            case 's':
                strcpy(s, argv[1]);
                user_send_msg(s);
                break;
            case 'p':
                strcpy(p, argv[1]);
                user_send_msg(p);
                break;
        }
    }
    else{
        printf("Error\n");
    }
    return 0;
}



struct sockaddr_nl user_addr;
struct sockaddr_nl kernal_addr;
struct nlmsghdr*nlh = NULL;
struct iovec iov;
struct msghdr msg;

void user_send_msg(char *send){
    // printf("%s\n", send);

    int sock;
    sock = socket(AF_NETLINK, SOCK_RAW, 1);
    memset(&user_addr, 0, sizeof(user_addr));
    user_addr.nl_family = AF_NETLINK;
    user_addr.nl_pid = getpid();
    user_addr.nl_groups = 0;

    bind(sock, (struct sockaddr*)&user_addr, sizeof(user_addr));

    memset(&kernal_addr, 0, sizeof(kernal_addr));
    kernal_addr.nl_family = AF_NETLINK;
    kernal_addr.nl_pid = 0;
    kernal_addr.nl_groups = 0;

    nlh = (struct nlmsghdr*)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    nlh -> nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh -> nlmsg_pid = getpid();
    nlh -> nlmsg_flags = 0;

    strcpy(NLMSG_DATA(nlh), send);  //save msg, to kernal

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh -> nlmsg_len; 
    msg.msg_name = (void *)&kernal_addr;
    msg.msg_namelen = sizeof(kernal_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    //send msg to kernal
    sendmsg(sock, &msg, 0); 


    recvmsg(sock, &msg, 0);
    printf("answer %s\n", NLMSG_DATA(msg.msg_iov -> iov_base));

    close(sock);
    return 0;
    
}
