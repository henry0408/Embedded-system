/*
逗号作为非输入控制符
*/


#include <stdio.h>

int main (void)
{
    int i,j;

    scanf("%d,%d",&i, &j); //e.g. 键盘需要输入：12,13

    printf("The number i is %d, the number j is %d\n", i, j);
    
    return 0;
}