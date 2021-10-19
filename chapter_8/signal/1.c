#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// ctrl+c: SIGINT, 终止
// ctrl+z: SIGSTP, 挂起

int main(int argc, char** argv)
{
    pid_t pgrp = getpgrp();
    //printf("%d\n", getpid());
    printf("%d\n", getpgrp());
    pid_t pid = fork();
    if(!pid){
        setpgid(0, 0);
        //printf("%d\n", getpid());
        printf("%d\n", getpgrp());
    }

    return 0;
}
