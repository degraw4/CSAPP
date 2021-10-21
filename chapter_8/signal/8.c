#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

// 测试某信号被阻塞变为待处理信号后，当阻塞结束，该信号会不会被接收(被阻塞的那一个信号，而不是取消阻塞后新的信号)
// 测试显式阻塞：阻塞结束后会被接收

void handler(int sig){
    printf("catch SIGINT\n");
}

int main(int argc, char** argv)
{
    sigset_t mask, prev;
    signal(SIGINT, handler);
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigprocmask(SIG_BLOCK, &mask, &prev);
    for(int i = 0; i < 10; ++i){
        printf("time: %d\n", i);
        sleep(1);
    }
    sigprocmask(SIG_SETMASK, &prev, NULL);
    return 0;
}
