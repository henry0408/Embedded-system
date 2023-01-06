/*比较两个数字大小，打印最大值*/

#include <stdio.h>

void max(int a, int b) // 函数名：max；形参：a, b；返回值：无（由于void）
{
    if (a>b){
        printf("%d\n", a);
    }
    else{
        printf("%d\n", b);
    }
}

int main (void){
    
    int i, j;
    i = 4;
    j = 5;
    max(i, j);
    
    return 0;
}