/*
互换两个数字（利用指针的概念）

首先，exchange这个函数不能实现数字互换，然而exchange2这个函数可以实现
注意的地方在于函数的写法

*/

#include <stdio.h>

void exchange(int * p, int * q){
    int * t;
    t = p;
    p = q;
    q = t;

    return;
}

void exchange2(int * p, int * q){
    int t;
    printf("%d\n", p);
    printf("%d\n", *p);
    t = *p;
    *p = *q;
    *q = t;
    printf("%d\n", p);
    printf("%d\n", *p);
}

int main (void){

    int a = 3;
    int b = 5;
    // exchange(&a, &b);
    // printf("a = %d, b = %d \n", a, b); // a = 3, b = 5

    exchange2(&a, &b);
    printf("a = %d, b = %d \n", a, b); // a = 5, b = 3

    return 0;
}