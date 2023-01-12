/*一维动态数组的构造*/

#include <stdio.h>
#include <malloc.h>

int main (void)
{
    int a[5]; //静态一维数组

    int len;

    int * pArr;
    printf("Please enter the length of the array: ");
    scanf("%d", &len);

    pArr = (int *)malloc(sizeof(int)*len); //其实效果就是int pArr[len]

    /*
    *pArr = pArr[0] = a[0]
    *(pArr + 1) = pArr[1] = a[1]
    */


    return 0;
}