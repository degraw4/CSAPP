#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    int x = 1;
    pid_t pid = fork();
    // fork之后，父子进程的x相互独立
    if(pid == 0){
        // child
        printf("child: %d\n", getpid());
        ++x;
        printf("child: %d\n", x);
    }else{
        // parent
        printf("parent: %d\n", getpid());
        printf("parent: %d\n", x);
    }
    // 父进程和子进程都可以执行
    printf("test who can get here: %d\n", getpid());

    // 能否二次分叉？可以
    if(pid == 0){
        // child
        printf("again child: %d\n", getpid());
    }else{
        // parent
        printf("again parent: %d\n", getpid());
    }

    return 0;
}
