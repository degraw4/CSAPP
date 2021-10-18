#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    fork();
    fork();
    printf("hello world.\n");
    waitpid(-1, 0, 0);
    return 0;
}
