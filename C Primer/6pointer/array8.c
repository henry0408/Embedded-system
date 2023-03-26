/*
指针变量加减运算的结果跟数据类型的长度有关，而不是简单地加 1 或减 1
*/

#include <stdio.h>

int main(){
    int a = 10;
    int *pa = &a;
    int *paa = &a;

    double b = 99.9;
    double *pb = &b;

    char c = '@';
    char *pc = &c;

    //最初的值
    printf("&a=%#X, &b=%#X, &c=%#X\n", &a, &b, &c);
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc);
    
    //加法运算
    pa++; pb++; pc++;
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc); //int每次+4，float每次+8，char每次+1
    
    //减法运算
    pa -= 2; pb -= 2; pc -= 2;
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc);
    
    //比较运算
    if(pa == paa){
        printf("same\n");
        printf("%d\n", *paa);
    }else{
        printf("different\n");
        printf("%d\n", *pa);
    }
    return 0;
}