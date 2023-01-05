/*求1-100之间所有能被3整除的数字之和*/

#include <stdio.h>

int main(void)
{
    int sum = 0;

    int i = 1;

    for (i = 1; i<= 100; i++)
    {
        if (i % 3 == 0)
        {
            sum = sum + i;
        }

    }

    printf("The sum is %d\n", sum);

    return 0;
}