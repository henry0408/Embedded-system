#include <stdio.h>

int main(void)
{
    int ten = 10;
    int two = 2;

    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two);
    printf("Doing it wrong: ");
    printf("%d minus %d is %d\n", ten); //发现后面两个值是内存中的任意值

    return 0;

}