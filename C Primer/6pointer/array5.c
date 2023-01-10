/*指针相减*/

#include <stdio.h>

int main (void)
{
    int * p;
    int * q;

    int a[5];
    p = &a[1];
    q = &a[3];

    printf("%d", q - p);

    return 0;
}