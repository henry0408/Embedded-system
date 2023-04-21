/* 剑指offer11.旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。
请返回旋转数组的**最小元素**。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。 

注意，数组 `[a[0], a[1], a[2], ..., a[n-1]]` 旋转一次 的结果为数组 `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]` 。

*/

#include <stdio.h>

int minArray(int* nums, int numbersSize)
{
	int left = 0;
	int right = numbersSize-1;
	while (left<right)
	{
		int mid = (left+right)/2;
        printf("%d %d %d\n",mid, left, right);
		
		//注意：不存在numbers[left] < numbers[right]的情况
		if((right-left) == 1)
		{
			printf("*******\n");
            return nums[right];
		}
		else if(nums[mid]>=nums[left])      //注意：一定要写等于号，不然例子3会出问题
		{
			left = mid;
		}
		else if(nums[mid]<=nums[right])
		{
			right = mid;
		}
	}
}

int main()
{
	int arr[5] = {2,4,6,0,1};
	int ans = minArray(arr,5);
	printf("%d\n",ans);             //输出0

    int arr1[7] = {2,4,4,6,1,2,2};
	int ans1 = minArray(arr1,7);
	printf("%d\n",ans1);            //输出1

    int arr2[7] = {2,2,2,2,2,1,2};
	int ans2 = minArray(arr2,7);
	printf("%d\n",ans2);            //输出1
}