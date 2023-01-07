/*全局变量和局部变量命名一致的问题*/

#include <stdio.h>

int i = 100;

void k (int i) // int i 命名一致
{
    printf("i = %d\n", i);
}

int main (void)
{
    k(8); //结果为i = 8, 说明全局变量会被局部变量代替
    return 0;
}


