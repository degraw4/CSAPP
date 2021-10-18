#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// 错误处理包装函数 & 错误报告函数

void unix_error(char* msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

pid_t Fork(){
    pid_t pid;
    if((pid = fork()) < 0){
        unix_error("Fork error.");
    }
    return pid;
}

int main(int argc, char** argv)
{
    printf("%d\n", getpid());
    printf("%d\n", getppid());
    // ehco $$

    return 0;
}
