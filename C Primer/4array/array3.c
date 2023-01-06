/*倒置一个数组

注意：倒置用到的是“互换”的概念，而不是反向输出（可以新建一个数组）
*/

#include <stdio.h>

int main (void)
{
    int a[5] = {1, 2, 3, 4, 5};

    int t;
    int i = 0;
    int j = 4;

    while (i<j){
        
        t = a[i];
        a[i] = a[j];
        a[j] = t;

        i = i+1;
        j = j-1;
    }

    for (int z = 0; z< 5; z++){
        printf("%d\n", a[z]);
    }

    return 0;
}