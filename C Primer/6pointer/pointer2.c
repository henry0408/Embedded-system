/*指针常见问题*/

#include <stdio.h>

int main (void)
{
    int * p;
    int i = 3;

    *p = i;

    printf("%d\n", *p);
    printf("%d\n", i);

    return 0;
}