/*指针常见问题2: 类型错误

warning: assignment to 'int' from 'int *' makes integer from pointer without a cast

p的类型是：int *
*q的类型是：int

导致*q = p时会出错

*/

#include <stdio.h>

int main (void)
{
    int i = 3;
    int * p;
    int * q;

    p = &i;
    *q = p;

    printf("%d\n", *q);

    return 0;
}