/*exe3的第二种解法：二分法满足时间复杂度要求*/

// #include <stdio.h>

// int findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
//     int odd;
//     int middle_index = (nums1Size + nums2Size)/2;
//     if((nums1Size + nums2Size)%2 == 1)
//         odd = 1;
//     else
//         odd = 0;
//     int mid = middle_index/2;
//     int count = 0;
//     while(count < middle_index)
//     {
//         if(nums2[mid]<nums1[mid])
//         {

//         }
//     }

// }

// int main()
// {
//     int len1 = 5;   //nums1长度
//     int len2 = 4;
//     int nums1[] = {1,5,6,9,10};
//     int nums2[] = {1,3,6,10};
    
//     int ans = findMedianSortedArrays(nums1,len1,nums2,len2);
//     printf("%d\n",ans);

//     int len3 = 2;
//     int len4 = 1;
//     int nums3[] = {1,3};
//     int nums4[] = {2};
//     int ans1 = findMedianSortedArrays(nums3,len3,nums4,len4);
//     printf("%d\n",ans1);

//     int len5 = 2;
//     int len6 = 2;
//     int nums5[] = {1,2};
//     int nums6[] = {3,4};
//     int ans2 = findMedianSortedArrays(nums5,len5,nums6,len6);
//     printf("%d\n",ans2);


// }