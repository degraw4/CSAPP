#include <stdio.h>

// true为x二进制表示中含有奇数个1，false为偶数个1

int OddOnes_1(int x) 
{
	int cnt = 0;
	while(x)
	{
		cnt++;
        // x & x-1，可以去掉x二进制中最右边的1
        // 最低位的掩码，只需 x ^ (x & (x-1))
		x &= x-1;
	}
	return cnt & 1;
}

/*
 * 第一次异或，某个位为1，代表从它开始向左连续两位中1的个数是奇数（异或的本质）。
 * 第二次异或，若结果第6位为1，那么代表上一次的结果的第6位和第8位有奇数个1，也就是原数中第6,7,8,9位中有奇数个1。
 * 同样，到第五次运算结束后，过第0位为1代表0到31位共奇数个1。
 * 整个过程就是不断的压缩信息
*/
int OddOnes_2(int x)
{
	x = x ^ (x >> 1);
	x = x ^ (x >> 2);
	x = x ^ (x >> 4);
	x = x ^ (x >> 8);
	x = x ^ (x >> 16);
	return x & 1;
}

int main(){
    int x = 0x1FFFFF;
    printf("%d\n", OddOnes_2(x));
}