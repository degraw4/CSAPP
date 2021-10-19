#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char** argv)
{
    sigset_t mask, prev_mask;
    sigaddset(&mask, SIGINT);
    // 阻塞信号SIGINT
    sigprocmask(SIG_BLOCK, &mask, &prev_mask);
    pause();
    // 解除阻塞
    //sigprocmask(SIG_SETMASK, &prev_mask, NULL);

    return 0;
}
