/* ��ָoffer11.��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��

����һ�����ܴ��� �ظ� Ԫ��ֵ������ nums ����ԭ����һ���������е����飬�����������ν�����һ����ת��
�뷵����ת�����**��СԪ��**�����磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ 1�� 

ע�⣬���� `[a[0], a[1], a[2], ..., a[n-1]]` ��תһ�� �Ľ��Ϊ���� `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]` ��

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
		
		//ע�⣺������numbers[left] < numbers[right]�����
		if((right-left) == 1)
		{
			printf("*******\n");
            return nums[right];
		}
		else if(nums[mid]>=nums[left])      //ע�⣺һ��Ҫд���ںţ���Ȼ����3�������
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
	printf("%d\n",ans);             //���0

    int arr1[7] = {2,4,4,6,1,2,2};
	int ans1 = minArray(arr1,7);
	printf("%d\n",ans1);            //���1

    int arr2[7] = {2,2,2,2,2,1,2};
	int ans2 = minArray(arr2,7);
	printf("%d\n",ans2);            //���1
}