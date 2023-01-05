/*判断一个数字是不是回文数*/

#include <stdio.h>

int main (void)
{
    int sum = 0;
    int val, num;

    printf("Please enter your num: \n");
    scanf("%d", &val);

    num = val;

    while (num) //只要num不是0就一直循环
    {
        sum = sum * 10 + num % 10;
        num /= 10;
    }

    if (sum == val){
        printf("Yes \n");
    }
    else{
        printf("No \n");
    }

    return 0;
}