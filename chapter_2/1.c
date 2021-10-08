#include <stdio.h>

int main(int argc, char** argv)
{
    unsigned a = 20;
    unsigned b = 30;
    unsigned c = a - b;
    printf("unsigned: %u\n", c);
    printf("signed: %d\n", c);

    if(a - b > 0)
        printf("minus bigger\n");
    else
        printf("minus smallger\n");

    if(a > b)
        printf("compare bigger\n");
    else
        printf("compare smallger\n");

    return 0;
}
