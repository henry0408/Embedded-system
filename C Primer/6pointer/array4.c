/*替换数组中的一个值*/

#include <stdio.h>

void replace (int * p)
{
    p [2] = 7;
    *(p+3) = 8;
    return;
}

int main (void)
{
    int a[5] = {1, 2, 3, 4, 5};
    printf("%d\n", *(a+1));

    printf("The 3th number is %d\n", a[2]);
    printf("The 4th number is %d\n", a[3]);

    replace(a);

    printf("The 3th number is %d\n", a[2]);
    printf("The 4th number is %d\n", a[3]);

    return 0;
}