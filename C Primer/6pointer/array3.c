/*通过一个函数输出数组所有内容
需要知道两个参数，一个是数组本身（相当于一个指针变量），另一个是数组长度

数组和字符串不同，字符串结尾永远有一个\n，但数组最后一位不一定是什么，这也是我们需要数组长度作为参数的原因
*/

#include <stdio.h>

void print_all(int *p, int len)
{
    // 由array2.c可以知道，*p = a[0]， *(p+1) = a[1]

    for (int i = 0; i< len; i++){
        printf("%d\n", *(p+i));
    }
    return;
}

int main (void)
{
    int a[5] = {1, 2, 3, 4, 5};

    int b[3][4];

    print_all(a, 5); // a的类型为int *

    return 0;
}