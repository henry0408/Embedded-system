/*malloc指针拷贝*/
#include <stdio.h>
#include <malloc.h>

void f(int * q)
{
    *q = 100;
    // free(q); //这样free掉之后，p中就是一个垃圾值
    return;
}

int main (void)
{
    int * p = (int *)malloc(sizeof(4));
    *p = 4;
    printf("The value of p is %d\n", *p); // 4
    f(p);
    printf("The value of p is %d\n", *p); // 100


    free(p);
    printf("The value of p is %d\n", *p); // 100

    return 0;
}