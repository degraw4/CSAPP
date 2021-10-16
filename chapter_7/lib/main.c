#include "header.h"

int main(){
    int x = 1, y = 2;
    int z = add(x, y);
    return 0;
}

// 生成静态库文件libop.a
// gcc -c add.c multi.c
// ar rcs libop.a add.o multi.o

// 两种链接静态库的编译格式
// gcc -static main.o ./libop.a 
// gcc -static main.o -L. -lop

// PS. 也可以直接将源文件和.o一起编译，例如
// gcc main.c libop.a 
// gcc main.c -L. -lop