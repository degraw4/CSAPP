#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// ps t中T表示挂起的进程

int main(int argc, char** argv)
{
    pid_t pid = fork();
    if(!pid){
        printf("child: %d\n", getpid());
        while(1);
    }
    else{
        printf("parent: %d\n", getpid());
        while(1);
    }

    return 0;
}
