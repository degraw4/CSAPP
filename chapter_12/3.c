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

// 任意线程调用exit，其对应进程下的所有线程终止

void* thread(void* argv){
    printf("peer thread\n");
    //return NULL;
    //pthread_exit(NULL);
    exit(0);
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
