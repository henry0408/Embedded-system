/* 计算1/1 + 1/2 + ... + 1/100 的和： 强制转换类型 */


#include <stdio.h>

int main (void)
{
    int i;

    float sum = 0;

    for (i = 1; i<=100; ++i)
    {
        // sum = sum + 1.0/i; //如果直接写1/i的话，结果会是1，原因是精度不同

        //另一种方法：强制转换类型：
        sum = sum + 1/(float) i;
    }

    printf("The sum is %f", sum);

    return 0;

}