#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    struct stat file_stat;
    stat("file", &file_stat);
    printf("size is: %ld\n", file_stat.st_size);

    int fd = open("file", O_RDWR|O_APPEND);
    fstat(fd, &file_stat);
    printf("size is: %ld\n", file_stat.st_size);

    close(fd);

    return 0;
}
