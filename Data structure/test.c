#include <stdio.h>

int main()
{
    // int a = 10;
    // int b, c, d;
    // b = a++;
    // c= ++a;
    // d = 10*a++;

    // printf("%d\n",d);

    int a = 1;
    a = ~a & 0x01;
    printf("%d\n",a);
}