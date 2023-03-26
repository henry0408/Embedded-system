/*多级指针2
静态变量不能跨函数使用
*/

#include <stdio.h>

void f (int **q)
{
    //*q就是p
    int i = 10;
    *q = &i;
}

void g (void)
{
    int i = 5;
    int *p = &i;
    printf("The value of *p is %d\n", *p);
    f(&p);
    printf("The value of *p is %d\n", *p); //语法没问题但逻辑有问题，因为f函数中，i变量是一个局部变量，f函数运行之后就会被释放了，所以*p读到了一个不属于我们分配的空间
}

int main (void)
{
    g();
    return 0;
}