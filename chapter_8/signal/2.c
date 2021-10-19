#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// 信号处理函数

void signal_handler(int sig){
    if(sig == SIGINT){
        // 2
        printf("catch signal SIGINT\n");
        return;
    }else if(sig == 10){
        // 10
        printf("catch signal 10\n");
        return;
    }
}

int main(int argc, char** argv)
{
    printf("my pid is %d\n", getpid());
    if(signal(SIGINT, signal_handler) == SIG_ERR){
        printf("signal error\n");
        exit(0);
    }
    if(signal(10, signal_handler) == SIG_ERR){
        printf("signal error\n");
        exit(0);
    }
    while(1);
    // pause();

    return 0;
}
