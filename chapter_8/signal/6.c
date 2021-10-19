#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// 信号处理程序和原程序不是并行运行的
// 信号处理程序返回后，原程序才继续运行

void handler(int sig){
    while(1){
        printf("handler\n");
        sleep(1);
    }
}

int main(int argc, char** argv)
{
    signal(SIGINT, handler);
    while(1){
        printf("main\n");
        sleep(1);
    }
    return 0;
}
