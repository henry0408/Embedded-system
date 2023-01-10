
#include <stdio.h>

int main (void)
{
    int a[5];
    int b[3][4];

    printf("%#X \n", &a[0]); //查看第一个元素的地址
    printf("%#X \n", &a); //查看数组地址，应该与第一个元素地址一样

    return 0;
}