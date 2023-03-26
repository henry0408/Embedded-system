/*
借助自增运算符来遍历数组元素
*/

#include <stdio.h>

int main (void)
{
    int a[5] = {8, 7, 10, 9, 4};

    int *p = a;

    int len = sizeof(a)/sizeof(int);    //算出一个数组的长度（元素的个数）

    for (int i = 0; i<len; i++)
    {
        //printf("The %dth element is %d\n", i, *p++);
        printf("The %dth element is %d\n", i, *(p+i));
    }


    return 0;
}