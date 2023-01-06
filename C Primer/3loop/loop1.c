#include <stdio.h>

int main(void)
{
    int i = 1;

    int sum = 0;

    for (i = 1; i <= 10; i+=2)
    {
        sum = sum + i;
    }

    printf("The sum is %d\n", sum);

    return 0;
}