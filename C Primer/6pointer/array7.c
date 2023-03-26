/*数组长度怎么求*/

#include <stdio.h>

int main (void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(int);

    printf("The length of the array is: %d\n", len);

    return 0;
}