#include <stdio.h>

int main (void)
{
    int a[5] = {1, 2, 3, 4, 5};

    int i;

    for (i = 0; i<5; i++){
        printf("The %dth number is %d \n", i, a[i]);
    }

    printf("%d \n", a[100]);

    return 0;
}