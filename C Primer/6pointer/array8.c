/*
ָ������Ӽ�����Ľ�����������͵ĳ����йأ������Ǽ򵥵ؼ� 1 ��� 1
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

    //�����ֵ
    printf("&a=%#X, &b=%#X, &c=%#X\n", &a, &b, &c);
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc);
    
    //�ӷ�����
    pa++; pb++; pc++;
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc); //intÿ��+4��floatÿ��+8��charÿ��+1
    
    //��������
    pa -= 2; pb -= 2; pc -= 2;
    printf("pa=%#X, pb=%#X, pc=%#X\n", pa, pb, pc);
    
    //�Ƚ�����
    if(pa == paa){
        printf("same\n");
        printf("%d\n", *paa);
    }else{
        printf("different\n");
        printf("%d\n", *pa);
    }
    return 0;
}