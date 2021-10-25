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

long ele_per_thread = 10000;
long thread_num = 10;
long sum[10];

void* thread_sum(void* argv){
    long id = (long)argv;
    long res = 0;
    long start = id * ele_per_thread;
    long end = start + ele_per_thread;
    for(long i = start; i < end; ++i)
        res += i;
    sum[id] = res;
}

int main(int argc, char** argv)
{
    pthread_t tid[thread_num];
    long id[thread_num];
    for(int i = 0; i < thread_num; ++i){
        id[i] = i;
        pthread_create(&tid[i], NULL, thread_sum, &id[i]);
    }

    for(int i = 0; i < thread_num; ++i)
        pthread_join(tid[i], NULL);

    return 0;
}
