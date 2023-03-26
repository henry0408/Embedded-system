// /*指针作为函数返回值*/

#include <stdio.h>
int *func(){
    int n = 100;
    return &n;              //warning: function returns address of local variable(返回了局部变量的地址)
}
int main(){
    int *p = func(), n;
    printf("hello\n");
    n = *p;
    printf("value = %d\n", n);          //结果为随机值
    return 0;
}