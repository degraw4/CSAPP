#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

// 未处理的信号不会排队，因此不能用信号作为时间的计数器
// 想通过SIGCHLD接收子进程，不能每次handler接收一个，因为处理时会阻塞其余的SIGCHLD
// 应该一次处理时循环接收所有的信号

void handler(int sig){
    if(sig == SIGCHLD){
        int olderrno = errno;
        while(waitpid(-1, NULL, 0) > 0){
            printf("Handler reaped child.\n");
        }
        if(errno != ECHILD){
            printf("waitpid error.\n");
            return;
        }
        sleep(1);
        errno = olderrno;
        return;
    }
}

int main(int argc, char** argv)
{
    signal(SIGCHLD, handler);

    for(int i = 0; i < 3; ++i){
        if(fork() == 0){
            printf("hello from child: %d\n", getpid());
            exit(0);
        }
    }

    while(1){
        printf("parent processing something...\n");
        sleep(1);
    }

    return 0;
}
