/*
空格作为非输入控制符
*/


// scanf(),判断输入结束的标志是空格和回车，所以输入字符串时，若中间有空格，空格后面的字符输入不进去，因为scanf已经停止输入了；


#include <stdio.h>

int main (void)
{
    int i,j;

    // scanf("%d %d",&i, &j); //注意，有空格，e.g. 键盘需要输入：12 13

    scanf("%d%d",&i, &j); //和上面效果相同，有空格，e.g. 键盘需要输入：12 13。

    printf("The number i is %d, the number j is %d\n", i, j);
    
    return 0;
}