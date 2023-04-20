/*给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

算法的时间复杂度应该为 `O(log (m+n))` */

#include <stdio.h>

int findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int middle_index = (nums1Size + nums2Size)/2;
    int*p1 = &nums1[0];
    int*p2 = &nums2[0];
    printf("The middle index is %d\n",middle_index);

    //int count = 0;
    for(int i = 0, j = 0, count = 0; ; ++count)
    {
        //printf("count is: %d\n",count);
        //printf("p1 is: %d, p2 is: %d\n",p1[i],p2[j]);
        //printf("%d %d\n",i,j);
        if(p1[i]<p2[j])
        {
            i++;
            if(count == middle_index)
            {
                //printf("******\n");
                return p1[i-1];
                //break;
            }
        }
        else
        {
            j++;
            if(count == middle_index)
            {
                //printf("******\n");
                return p2[j-1];
                //break;
            }
        }
        
    }
}

int main()
{
    int len1 = 5;   //nums1长度
    int len2 = 4;
    int nums1[] = {1,5,6,9,10};
    int nums2[] = {1,3,6,10};
    
    int ans = findMedianSortedArrays(nums1,len1,nums2,len2);
    printf("%d\n",ans);

    int len3 = 2;
    int len4 = 1;
    int nums3[] = {1,3};
    int nums4[] = {2};
    int ans1 = findMedianSortedArrays(nums3,len3,nums4,len4);
    printf("%d\n",ans1);

    int len5 = 2;
    int len6 = 2;
    int nums5[] = {1,2};
    int nums6[] = {3,4};
    int ans2 = findMedianSortedArrays(nums5,len5,nums6,len6);
    printf("%d\n",ans2);


}