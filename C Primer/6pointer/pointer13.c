/*多级指针3
动态内存可以跨函数使用
*/

#include <stdio.h>
#include <malloc.h>

void f(int ** q)
{
    *q = (int*)malloc(sizeof(int));
    **q = 5;
}

int main (void)
{
    int * p;
    f(&p);
    printf("%d\n", *p);

    return 0;
}