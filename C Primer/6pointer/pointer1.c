/*指针基础知识：指针和指针变量*/

#include <stdio.h>

int main (void)
{
    int *p; //此时，p值为空，p有自己的地址；注意，p为变量名，变量的类型是int *。
    int i = 3; // 此时，i值为3，i有自己的地址

    p = &i; //此时，p值为i的地址，p有自己的地址
    int j;

    j = *p; //j为p的值对应地址的变量的值（即i的值）

    printf("i = %d, j = %d\n", i, j);

    return 0;
}