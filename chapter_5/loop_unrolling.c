#include <stdio.h>
#include <time.h>
#define OP *
typedef double data_t;

// sample add
void add_1(data_t arr[], int len, data_t* dest){
    for(int i = 0; i < len; i++)
        *dest += arr[i];
}

// remove memory ref
void add_2(data_t arr[], int len, data_t* dest){
    data_t ans = 0;
    for(int i = 0; i < len; i++)
        ans += arr[i];
    *dest = ans;
}

// 2*1 loop unrolling
void add_3(data_t arr[], int len, data_t* dest){
    data_t ans = 0;
    int limit = len - 1;
    int i;
    for(i = 0; i < limit; i += 2){
        ans += arr[i];
        ans += arr[i+1];
    }
    if(i < len)
        ans += arr[i];
    *dest = ans;
}

// 2*2 loop unrolling
void add_4(data_t arr[], int len, data_t* dest){
    data_t ans1 = 0, ans2 = 0;
    int limit = len - 1;
    int i;
    for(i = 0; i < limit; i += 2){
        ans1 += arr[i];
        ans2 += arr[i+1];
    }
    if(i < len)
        ans1 += arr[i];
    *dest = ans1 + ans2;
}

data_t main(data_t argc, char** argv)
{
    data_t arr[1000000] = {2};
    int len = 1000000;
    data_t answer;
    clock_t start_time, end_time;

    start_time = clock();
    add_1(arr, len, &answer);
    end_time = clock();
    printf("%f\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

    start_time = clock();
    add_2(arr, len, &answer);
    end_time = clock();
    printf("%f\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

    start_time = clock();
    add_3(arr, len, &answer);
    end_time = clock();
    printf("%f\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);
    
    start_time = clock();
    add_4(arr, len, &answer);
    end_time = clock();
    printf("%f\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}
