#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

// 显式等待信号

volatile sig_atomic_t pid;

void handler(int sig){
    int olderrno = errno;
    pid = waitpid(-1, NULL, 0);
    errno = olderrno;
}

int main(int argc, char** argv)
{
    sigset_t mask, prev_mask;
    signal(SIGCHLD, handler);
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);

    while(1){
        // 类shell程序中，fork时阻塞SIGCHLD
        sigprocmask(SIG_BLOCK, &mask, &prev_mask);
        if(fork() == 0){
            exit(0);
        }

        // 显式等待SIGCHLD
        pid = 0;
        // while(!pid)
        //     sigsuspend(&prev_mask);
        if(!pid)
            sigsuspend(&prev_mask);
        
        sigprocmask(SIG_SETMASK, &prev_mask, NULL);

        printf("wait over\n");
    }
    

    return 0;
}
