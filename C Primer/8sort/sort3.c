/*选择排序

把最小的提出来，放在最前面

*/


#include <stdio.h>

void sort (int* arr, int len)
{
    //printf("%d\n", arr[0]);
    int i, j, swap;
    for (i = 0; i < len-1; i++)
    {
        int min = arr[i];
        for (j = i+1; j < len; j++)
        {
            if (arr[j] <= min)
            {
                min = arr[j];
                swap = arr[i];
                arr[i] = min;
                arr[j] = swap;

            }
        }
    }
}

int main (void)
{
    int a[6] = {2, -8, 10, 8, 9, -1};
    sort(a,6);

    for (int i = 0; i<6; i++){
        printf("%d ",a[i]);
    }

    return 0;
}