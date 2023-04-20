/*
给你两个按 **非递减顺序** 排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n` ，分别表示 `nums1` 和 `nums2` 中的元素数目。

请你 **合并** `nums2` 到 `nums1` 中，使合并后的数组同样按 **非递减顺序** 排列。

**注意：**最终，合并后数组不应由函数返回，而是存储在数组 `nums1` 中。为了应对这种情况，`nums1` 的初始长度为 `m + n`，其中前 `m` 个元素表示应合并的元素，后 `n` 个元素为 `0` ，应忽略。`nums2` 的长度为 `n` 
*/

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=m-1;
    int j=n-1;
    int tail = m+n-1;
    
    while(i >= 0 || j >= 0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[tail] = nums1[i];
            tail--;
            i--;
        }
        else if(nums1[i]<=nums2[j])
        {
            nums1[tail] = nums2[j];
            tail--;
            j--;
        }
        else if(i <0)
        {
            nums1[tail] = nums2[j];
            tail--;
            j--;
        }
        else if(j<0)
        {
            nums1[tail] = nums1[i];
            tail--;
            i--;
        }
    }
}

int main()
{
    int nums1[6] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[3] = {2,5,6};
    int n = 3;
    merge(nums1, 6, m, nums2, 3, n);
    for(int i = 0; i<6;i++)
    {
        printf("%d ",nums1[i]);
    }
    printf("\n");
    return 0;
}