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

int main(int argc, char** argv)
{
    printf("main thread\n");
    sleep(3);
    printf("main pid is %ld\n", pthread_self());
    //pthread_cancel(pid);
    pthread_cancel(pthread_self());
    printf("test\n");

    return 0;
}
