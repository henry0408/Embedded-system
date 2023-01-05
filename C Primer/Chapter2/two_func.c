#include <stdio.h>

void butler(void);

int main(void)
{
    printf("line 1 \n");
    butler();
    printf("line 2 \n");

    return 0;
}

void butler(void)
{
    printf("butler line \n");
}