#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BLOCK 32

void transpose(int dim, int src[][dim], int dst[][dim]){
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            dst[i][j] = src[j][i];
}

// 每次对src和dst各读入一个block
// 即BLOCKING技术不是向cache中单独读入一行或者读入一列(实际上也无法读入一列)，各自的前几行(不一定是正方形)
// 各自读入block之后，dst还会出现不命中当前block的情况，需要替换多次block(column/MAX_BLOCK次)，但仍然大大提升了效率
// 内部循环也可以用循环展开，或者临时变量提出src，防止cache只够一个block的大小导致src和dst的读写造成的抖动
void faster_transpose(int dim, int src[][dim], int dst[][dim]){
    for(int i = 0; i < dim; i += MAX_BLOCK)
        for(int j = 0; j < dim; j += MAX_BLOCK)
            for(int k = i; k < i + MAX_BLOCK; k++)
                for(int l = j; l < j + MAX_BLOCK; l++)
                    if(k < dim && l < dim)
                        dst[k][l] = src[l][k];
}

int main(int argc, char** argv)
{
    int src[1000][1000], dst[1000][1000];
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j< 1000; j++)
            src[i][j] = rand() % 10000;
            
    clock_t start, end;
    start = clock();
    transpose(1000, src, dst);
    end = clock();
    printf("%lf\n", (double)(end - start)/CLOCKS_PER_SEC);  

    start = clock();
    faster_transpose(1000, src, dst);
    end = clock();
    printf("%lf\n", (double)(end - start)/CLOCKS_PER_SEC);  

    return 0;
}
