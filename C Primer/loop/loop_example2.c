/*求斐波拉契序列中第n项的值
1 2 3 5 8 13 21 34 ...
*/

#include<stdio.h>

int main (void)
{
    int f1 = 1;
    int f2 = 2;
    int value = 0;

    printf("Please enter a number n: \n");

    int n;
    scanf("%d", &n);

    if (n == 1){
        value = f1;
    }
    else if (n == 2){
        value = f2;
    }
    else{
        for (int i = 3; i <= n; ++i){
            value = f1+f2;
            f1 = f2;
            f2 = value;
        }
    }

    printf("The value of the nth number is %d\n", value);

    return 0;
}