/*多级指针*/

#include <stdio.h>

int main (void)
{
    int a = 5;
    int * p = &a;
    int ** q = &p; //储存指针变量的地址
    int *** r = &q;

    printf("The value of a is %d\n", a);
    printf("The value of &a is %d\n", &a);

    printf("The value of *p is %d\n", *p);
    printf("The value of p is %d\n", p);
    printf("The value of &p is %d\n", &p);

    printf("The value of *q is %d\n", *q);
    printf("The value of q is %d\n", q);
    printf("The value of &q is %d\n", &q);

    printf("i = %d\n", ***r);

    return 0;
}

