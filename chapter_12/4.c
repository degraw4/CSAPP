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

// pthread_cancel取消主线程本身，但是test仍可以打印?

void* thread(void* argv){
    printf("peer thread\n");
    for(int i = 0; i < 10; i++){
        printf("%d\n", i);
        sleep(1);
    }
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
    //pthread_cancel(pid);
    pthread_cancel(pthread_self());
    printf("test\n");

    return 0;
}
