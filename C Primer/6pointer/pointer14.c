// /*ָ����Ϊ��������ֵ*/

#include <stdio.h>
int *func(){
    int n = 100;
    return &n;              //warning: function returns address of local variable(�����˾ֲ������ĵ�ַ)
}
int main(){
    int *p = func(), n;
    printf("hello\n");
    n = *p;
    printf("value = %d\n", n);          //���Ϊ���ֵ
    return 0;
}