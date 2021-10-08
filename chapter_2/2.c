#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIN (- INT_MAX - 1)

// 检验运算是否溢出

int tadd_ok(int x, int y){
    int sum = x + y;
    if(x > 0 && y > 0 && sum < 0)
        return 0;
    if(x < 0 && y < 0 && sum > 0)
        return 0;
    return 1;
}

int tminus_ok(int x, int y){
    if(x >= 0 && y == INT_MIN)
        return 0;
    if(x < 0 && y == INT_MIN)
        return 1;
    return tadd_ok(x, -y);
}

int tmult_ok(int x, int y){
    int p = x * y;
    return !x || p/x == y;
}

int main(int argc, char** argv)
{
    int x = 483647;
    int y = 2147481111;
    printf("%d\n", tadd_ok(x, y));
    printf("%d\n", tminus_ok(x, y));
    printf("%d\n", tmult_ok(x, y));

    return 0;
}
