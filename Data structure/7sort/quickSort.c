#include <stdio.h>

int find_pos(int *p, int low, int high)
{
    int num = p[low];
    while(low < high)
    {
        while(low<high && p[high]>=num)
        {
            high--;
        }
        p[low] = p[high];
        while(low<high && p[low]<=num)
        {
            low++;
        }
        p[high] = p[low];
    }

    p[low] = num;

    return low;     //或者return high也一样
}


void quick_sort(int *p, int low, int high)
{
    int pos;
    if(low < high)
    {
        pos = find_pos(p, low, high);
        quick_sort(p, pos+1, high);     //先排右侧
        quick_sort(p, low, pos-1);      //再排左侧
    }
}

void print_info(int *p, int len)
{
    for(int i = 0; i<len; i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {3,1,5,2,7};
    quick_sort(arr, 0, 5);
    print_info(arr,5);
}