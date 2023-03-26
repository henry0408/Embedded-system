/*动态数组构造2*/
#include <stdio.h>
#include <malloc.h>

int main (void)
{
    int *pArr;
    int len;

    printf("The length is: ");
    scanf("%d", &len);
    pArr = (int *)malloc(sizeof(int)*len);

    int val;
    for (int i = 0; i<len; i++){
        printf("Please enter the %dth number: ", i);
        scanf("%d", &val);

        *(pArr + i) = val;
    }

    for(int i = 0; i<len; i++){
        printf("%d\n", pArr[i]);
    }

    return 0;
}