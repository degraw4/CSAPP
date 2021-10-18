#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char** argv)
{
    int status, i;
    pid_t pid;
    for(i = 0; i < 10; ++i)
        if((pid = fork()) == 0){
            // 虽然子进程立刻终止，但是仍有可能在父进程之后才执行
            exit(100 + i);
        }
    
    // 循环回收每一个子进程
    while((pid = waitpid(-1, &status, 0)) > 0){
        // 如果子进程exit正常终止
        if(WIFEXITED(status))
            printf("child %d terminated normally with exit status: %d.\n", pid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally.\n", pid);
    }

    // 回收完所有子进程后，再次回收，waitpid返回-1，且errno为ECHILD
    if(errno != ECHILD){
        printf("waitpid error,\n");
        exit(-1);
    }
    return 0;
}
