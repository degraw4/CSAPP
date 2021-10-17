#include "header.h"

int main(){
    int x = 1, y = 2;
    int z = add(x, y);
    return 0;
}

// 生成动态库
// gcc -shared -fpic add.c multi.c -o libop.so
// 加载时链接
// gcc main.c ./libop.so 