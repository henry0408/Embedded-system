/*malloc 用法*/

#include <stdio.h>
#include <malloc.h>

int main (void)
{
    printf("The size of int is %d\n", sizeof(int));
    int * p = (int *)malloc(sizeof (int)); //sizeof(int)可以替换为任何自己规定的int
    printf("%d\n", *p);
    printf("The size of *p is %d\n", sizeof(*p));
    *p = 5;

    free(p);

    return 0;
}