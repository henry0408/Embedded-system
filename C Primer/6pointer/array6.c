/*ͨ��һ���������������������
��Ҫ֪������������һ�������鱾���൱��һ��ָ�����������һ�������鳤��

������ַ�����ͬ���ַ�����β��Զ��һ��\n�����������һλ��һ����ʲô����Ҳ��������Ҫ���鳤����Ϊ������ԭ��
*/

#include <stdio.h>

// void print_all(int *p, int len)
// {
//     // ��array2.c����֪����*p = a[0]�� *(p+1) = a[1]

//     for (int i = 0; i< len; i++){
//         printf("%d\n", *(p+i));
//     }
//     return;
// }

void print_all(int **p, int len)
{
    **p = 50;
    return;
}

void print_all2(int **p, int len)
{
    
    **p = 50;
    return;
}


int main (void)
{
    int a[5] = {1, 2, 3, 4, 5};                                   

    int *b = &*a;  //��&a[0]һ��
    print_all(&b,6);

    printf("%d\n", a[0]);

    //print_all(a, 5); // a������Ϊint *

    //print_all(&a[0], 5); 

    //print_all(&a, 5);
     



    return 0;
}