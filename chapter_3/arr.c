#include <stdio.h>

int main(int argc, char** argv)
{
    int n = 10;
    int arr1[n];
    int arr2[3*5];

    union{
        double d;
        unsigned long u;
    } temp;

    temp.d = 10.5;
    // union内部共享内存，因此可以实现不改变bits的类型转换，只改变bits的解释方式
    unsigned long a = temp.u;
    // =会导致强制类型转换，对于浮点和整数之间改变了bits
    unsigned long b = temp.d;
    printf("%lu\n", a);
    printf("%lu\n", b);

    return 0;
}
