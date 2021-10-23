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

// 主线程调用pthread_exit，会等待其他所有线程终止，然后自身和进程终止
// 其余线程调用pthread_exit，相当于本身的进程例程函数结束返回

void* thread(void* argv){
    printf("peer thread\n");
    //return NULL;
    pthread_exit(NULL);
}

int main(int argc, char** argv)
{
    pthread_t pid;
    pthread_create(&pid, NULL, thread, NULL);
    printf("main thread\n");
    sleep(3);
    printf("main pid is %ld\n", pthread_self());
    printf("peer pid is %ld\n", pid);
    pthread_exit(NULL);
    printf("process is already terminated\n");

    return 0;
}
