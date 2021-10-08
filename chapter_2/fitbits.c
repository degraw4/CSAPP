#include <stdio.h>

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */


// 判断 x 能否用一个 n 位的补码表示, x 是32位的
// 将 x 左移（32-n）再右移回去，判断这样操作之后是否与原来的 x 相等
int fitsBits(int x, int n) {
  int c=33+~n;
  int t=(x<<c)>>c;
  return !(x^t);
}


int main(int argc, char** argv)
{
    

    return 0;
}
