// #include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
    void* handler;
    int (*add) (int, int);
    char* error;

    // 运行时动态链接add
    handler = dlopen("./libop.so", RTLD_LAZY);
    if(!handler){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // 得到add函数的指针
    add = dlsym(handler, "add");
    if(error = dlerror() != NULL){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // use add()
    int x = 1, y = 2;
    int z = add(x, y);

    // unload
    if(dlclose(handler) < 0){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    return 0;
}

// gcc -rdynamic main.c -ldl
// -ldl: dlfcn.so