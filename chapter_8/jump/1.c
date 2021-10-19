#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <setjmp.h>

// setjmp调用一次，但是返回多次

jmp_buf buf;
int error_1 = 0;
int error_2 = 1;

void bar(), foo();

int main(int argc, char** argv)
{
    // 第一次为调用时返回0
    // 后续的返回是相应的longjmp的返回
    switch(setjmp(buf)){
        case 0:
            printf("No error.\n");
            foo();
            break;
        case 1:
            printf("Error 1.\n");
            break;
        case 2:
            printf("Error 2.\n");
            break;
        default:
            printf("Unknown error.\n");
    }

    return 0;
}

void foo(){
    if(error_1)
        longjmp(buf, 1);
    bar();
}

void bar(){
    if(error_2)
        longjmp(buf, 2);
}

