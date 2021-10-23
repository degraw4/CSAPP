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
#include <semaphore.h>

volatile long cnt = 0;
sem_t mutex;

void* thread(void* argv){
    long time = (long)argv;
    for(int i = 0; i < time; ++i){
        sem_wait(&mutex);
        cnt++;
        sem_post(&mutex);
    }
    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t tid1, tid2;
    long time = 500000;
    sem_init(&mutex, 0, 1);
    pthread_create(&tid1, NULL, thread, (void*)time);
    pthread_create(&tid2, NULL, thread, (void*)time);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("%ld\n", cnt);

    return 0;
}
