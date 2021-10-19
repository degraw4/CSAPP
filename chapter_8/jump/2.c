#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <setjmp.h>
#include <signal.h>

// setjmp调用一次，但是返回多次

jmp_buf buf;

void handler(int sig){
    siglongjmp(buf, 1);
}

int main(int argc, char** argv)
{
    if(!sigsetjmp(buf, 1)){
        signal(SIGINT, handler);
        printf("starting\n");
    }
    else{
        printf("restarting\n");
    }

    while(1){
        sleep(1);
        printf("processing...\n");
    }

    return 0;
}