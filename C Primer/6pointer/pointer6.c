/*指针变量占用的内存永远都是4个字节*/

#include <stdio.h>

int main (void)
{
    char ch = 'A';
    int num = 12;
    float val = 11.2;
    double val2  = 13.4;

    char * p = &ch;
    int * q = &num;
    float * t = &val;

    printf("The size of char is %d\n", sizeof(ch));
    printf("The size of int is %d\n", sizeof(num));
    printf("The size of float is %d\n", sizeof(val));
    printf("The size of double is %d\n", sizeof(val2));

    printf("The size of char * pointer is %d\n", sizeof(p));
    printf("The size of int * pointer is %d\n", sizeof(q));
    printf("The size of float * pointer is %d\n", sizeof(t));

    return 0;
}