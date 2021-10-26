#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <setjmp.h>
#include <signal.h>

// setjmp调用一次，但是返回多次
// 后续的返回使得整个程序从返回处重新执行，但是保持了上次返回后执行的变量

jmp_buf buf;

void handler(int sig){
    siglongjmp(buf, 1);
}

int main(int argc, char** argv)
{
    int i = 0;
    if(!sigsetjmp(buf, 1)){
        signal(SIGINT, handler);
        printf("starting\n");
    }
    else{
        printf("restarting\n");
    }

    while(1){
        sleep(1);
        printf("%d\n", i++);
    }

    return 0;
}