/*
�����������������������Ԫ��
*/

#include <stdio.h>

int main (void)
{
    int a[5] = {8, 7, 10, 9, 4};

    int *p = a;

    int len = sizeof(a)/sizeof(int);    //���һ������ĳ��ȣ�Ԫ�صĸ�����

    for (int i = 0; i<len; i++)
    {
        //printf("The %dth element is %d\n", i, *p++);
        printf("The %dth element is %d\n", i, *(p+i));
    }


    return 0;
}