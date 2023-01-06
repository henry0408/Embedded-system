/*前自增和后自增的比较*/

#include <stdio.h>

int main (void)
{
    int i, j, k, m;

    i = j = 3;

    k = i++; // k = 3: 后自增，整体表达式是i+1之前的值
    m = ++j; // m = 4

    printf("The values are: i = %d, j = %d, k = %d, m = %d", i, j, k, m);

    return 0;
}