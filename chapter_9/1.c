#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    int fd = open("file", O_RDWR);
    char* ptr = mmap(NULL, 100, PROT_READ, MAP_PRIVATE, fd, 0);
    for(int i = 0; i < 10; i++){
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}
