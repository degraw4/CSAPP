#include<iostream>
using namespace std;
int main()
{
    int a = 2;  	    int *p = &a;
    double b = 1;   	double *q = &b;
    float c = 3;    	float *l = &c;
    char d = 's';      	char *s = &d;


    cout << sizeof(a) << " " <<sizeof(p) << endl;
    cout << sizeof(b) << " " << sizeof(q) << endl;
    cout << sizeof(c) << " " << sizeof(l) << endl;
    cout << sizeof(d) << " " << sizeof(s) << endl;
    return 0;
}