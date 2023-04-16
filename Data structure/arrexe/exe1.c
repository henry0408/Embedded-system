/*二分法查找*/

/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target ，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。（假设 nums 中的所有元素是不重复的。）*/

#include <stdio.h>

int find_val(int*arr, int length, int num)
{
    // left, right, mid是index
    int left = 0;
    int right = length-1;
    int mid;
    while(right >= left)        //如果右侧的index=左侧的index，意味着到了最中间的元素
    {
        mid = (right+left)/2;
        if(arr[mid]>num)
        {
            right = mid-1;
        }
        else if (arr[mid]<num)
        {
            left = mid+1;
        }
        else
        {
            printf("Exist\n");
            return mid;
        }
    }
    printf("Not exist\n");
    return -1;
}

int main()
{
    int arr[5] = {1,5,9,34,50};
    printf("The index is %d\n",find_val(arr, 5, 34));

    return 0;
}


