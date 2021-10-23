#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <pthread.h>

// 多线程编译时加上 -lpthread
// 每个线程要有线程实例函数
// pthread_create返回后，主线程和对等线程同时运行

void* thread(void* argv){
    printf("peer thread\n");
    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t pid;
    pthread_create(&pid, NULL, thread, NULL);
    printf("main thread\n");
    printf("main pid is %ld\n", pthread_self());
    printf("peer pid is %ld\n", pid);
    pthread_join(pid, NULL);
    exit(0);

    return 0;
}
