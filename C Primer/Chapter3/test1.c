/*
非输入控制符1
*/


#include <stdio.h>

int main (void)
{
    int i;

    // scanf("%d",&i); //正常写法(无非输出控制符)
    scanf("m%d",&i); //加入非输入控制符m，需要键盘输入m123，最后i的结果才是123，否则错误

    //尝试在键盘输入m123n，m12n3，看看结果有何不同

    printf("The number i is %d\n", i);

    printf("m%d\n",i);
    
    return 0;
}