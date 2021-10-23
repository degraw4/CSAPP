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

// pthread_join

void* thread(void* argv){
    printf("peer thread\n");
    sleep(5);
    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t pid;
    pthread_create(&pid, NULL, thread, NULL);
    printf("main thread\n");
    sleep(3);
    printf("main pid is %ld\n", pthread_self());
    printf("peer pid is %ld\n", pid);
    pthread_join(pid, NULL);
    printf("peer thread over\n");

    return 0;
}
