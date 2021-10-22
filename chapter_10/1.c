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
    int fd = open("file", O_RDWR|O_APPEND);
    char buf[1024] = "";
    int result1 = read(fd, buf, 5);
    printf("%d\n", result1);
    lseek(fd, 0, SEEK_SET);
    result1 = read(fd, buf, 1024);
    printf("%d\n", result1);
    result1 = read(fd, buf, 1024);
    printf("%d\n", result1);
    close(fd);

    fd = open("file", O_RDWR|O_APPEND);
    result1 = write(fd, "abcdefg\n", 8);
    printf("%d\n", result1);

    close(fd);

    return 0;
}
