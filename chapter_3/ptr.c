#include <stdio.h>

int main()
{
    int a = 2;  	    int *p = &a;
    double b = 1;   	double *q = &b;
    float c = 3;    	float *l = &c;
    char d = 's';      	char *s = &d;

    printf("%ld %ld\n",sizeof(a), sizeof(p));
    printf("%ld %ld\n",sizeof(b), sizeof(q));
    printf("%ld %ld\n",sizeof(c), sizeof(l));
    printf("%ld %ld\n",sizeof(d), sizeof(s));
    
    return 0;
}