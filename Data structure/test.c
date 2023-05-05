#include <stdio.h>

int find_pos(int*arr, int left, int right)
{
    int num = arr[left];
    while(left < right)
    {
        while(left<right && arr[right]>= num)
        {
            right--;
        }
        arr[left] = arr[right];
        while(left<right && arr[left] <= num)
        {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = num;
    return left;
}


void quick_sort(int *arr, int left, int right)
{
    if(left < right)
    {
        int pos = find_pos(arr, left, right);
        quick_sort(arr, pos+1, right);
        quick_sort(arr, left, pos-1);
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
    int arr[] = {1,9,2,-3,0,5};
    quick_sort(arr, 0, 6-1);
    print_info(arr, 6);
}