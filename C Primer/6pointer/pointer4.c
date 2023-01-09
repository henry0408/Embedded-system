/*指针常见问题3:

q中的内容是一个垃圾地址；q赋给p之后，p也是垃圾值，取*q时相当于把垃圾地址中的数值取出来
不能直接print *q的原因是：*q所代表的内存单元的权限并没有分配给本程序

*/

#include <stdio.h>

int main (void)
{
    int i = 3;
    int * p;
    int * q;

    p = &i;
    // p = q;

    printf("%d\n", *p); //输出结果是垃圾值，因为q中的内容是一个垃圾地址；q赋给p之后，p也是垃圾值

    // printf("%d\n", *q);

    return 0;
}