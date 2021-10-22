#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>

int main(int argc, char** argv)
{
    int x = 0;
    int* p1 = (int*)malloc(8);
    int* p2 = (int*)malloc(1024);
    int* p3 = (int*)malloc(256 * 1024);
    printf("%x\n", &x);
    printf("%x\n", p3);
    printf("%x\n", p2);
    printf("%x\n", p1);

    return 0;
}
