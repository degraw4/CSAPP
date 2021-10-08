#include <stdio.h>

// P.S 逻辑右移可以用unsigned自动实现

int is_shifts_are_arithmetic(void)
{
	int x = ~0;
	return x >> 1 == x;
}

int main(int argc, char const *argv[])
{
	
	printf("%d\n", is_shifts_are_arithmetic());
	return 0;
}