/*多个loop嵌套*/

#include <stdio.h>

int main (void)
{
    int i, j;

    for (i = 0; i< 5; ++i)
    {
        printf("ee\n");
        for (j = 2; j < 5; ++j)
        {
            printf("haha\n");
        }
    }

    return 0;
}