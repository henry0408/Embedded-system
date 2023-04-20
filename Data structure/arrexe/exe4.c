/*
���������� **�ǵݼ�˳��** ���е��������� `nums1` �� `nums2`�������������� `m` �� `n` ���ֱ��ʾ `nums1` �� `nums2` �е�Ԫ����Ŀ��

���� **�ϲ�** `nums2` �� `nums1` �У�ʹ�ϲ��������ͬ���� **�ǵݼ�˳��** ���С�

**ע�⣺**���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ `nums1` �С�Ϊ��Ӧ�����������`nums1` �ĳ�ʼ����Ϊ `m + n`������ǰ `m` ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� `n` ��Ԫ��Ϊ `0` ��Ӧ���ԡ�`nums2` �ĳ���Ϊ `n` 
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