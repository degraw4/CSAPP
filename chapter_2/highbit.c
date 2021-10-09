#include <stdio.h>

// O(logn)
unsigned int get_hight_bit(unsigned int a)
{
    unsigned int prev = a, curr = a;
    while(curr)
    {
        prev = curr;
        curr &= curr - 1;
    }
    return prev;
}

// O(loglogn)
// 将最高位的1向后扩散到比它低的所有位置，再加一，右移
unsigned hight_bit(unsigned x){//0010 1100 0000 0000 0000 0000 0000 0000 0000 0001
	x = x|(x>>1);              //0011 1110 0000 0000 0000 0000 0000 0000 0000 0000
	x = x|(x>>2);              //0011 1111 1000 0000 0000 0000 0000 0000 0000 0000
	x = x|(x>>4);              //0011 1111 1111 1000 0000 0000 0000 0000 0000 0000
	x = x|(x>>8);              //0011 1111 1111 1111 1111 1000 0000 0000 0000 0000
	x = x|(x>>16);             //0011 1111 1111 1111 1111 1111 1111 1111 1111 1111
	// x + 1                   //0100 0000 0000 0000 0000 0000 0000 0000 0000 0000
	return (x+1) >> 1;         //0010 0000 0000 0000 0000 0000 0000 0000 0000 0000
}

int main(int argc, char** argv)
{
    printf("%d\n", hight_bit(127));

    return 0;
}
