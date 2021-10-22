#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

// opendir: 打开目录，返回目录流
// readdir：读取目录流，一次返回目录中的下一项，读取到最后一项则返回NULL
// struct dirent：目录中的项结构体，包含name和inode

int main(int argc, char** argv)
{
    DIR* streamp;
    struct dirent* dep;

    streamp = opendir("../chapter_10");
    errno = 0;
    while((dep = readdir(streamp))!=NULL){
        printf("Found file: %s, inode num: %ld\n", dep->d_name, dep->d_ino);
    }

    if(errno != 0){
        printf("readdir errno\n");
        exit(-1);
    }

    closedir(streamp);

    return 0;
}
