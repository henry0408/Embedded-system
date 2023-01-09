/*指针常见问题1：野指针

所示例子，虽然可能不报错，但实际上是有问题的。
int * p初始化的时候，p中其实（可能）存储了一个垃圾值。
当使用*p = i时， 相当于把这个垃圾值作为地址的变量进行赋值。

*/

#include <stdio.h>

int main (void)
{
    int * p;
    int i = 3;

    *p = i;

    printf("%d\n", *p);
    printf("%d\n", i);

    return 0;
}