#include <stdio.h>

int main (void)
{
    // int i;
    // for (i = 1; i <= 4; i++){
    //     printf("%d\n", i);
    // }
    // printf("The final value of i is: %d\n", i);

    int i;
    for (i = 2; i <= 3; i++){
        printf("%d\n", i);
        if (i == 3){
            break;
        }
    }
    printf("The final value of i is: %d\n", i);

    return 0;
}