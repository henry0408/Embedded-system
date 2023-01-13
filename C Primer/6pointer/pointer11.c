/*多级指针*/

#include <stdio.h>

int main (void)
{
    int a = 5;
    int * p = &a;
    int ** q = &p; //储存指针变量的地址
    int *** r = &q;

    printf("i = %d\n", ***r);

    return 0;
}