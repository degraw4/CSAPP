#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    execve("./w", NULL, NULL);
    // execv调用程序且不返回
    printf("test\n");

    return 0;
}
