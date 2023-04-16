/*���ַ�����*/

/*����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target ��
дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1�������� nums �е�����Ԫ���ǲ��ظ��ġ���*/

#include <stdio.h>

int find_val(int*arr, int length, int num)
{
    // left, right, mid��index
    int left = 0;
    int right = length-1;
    int mid;
    while(right >= left)        //����Ҳ��index=����index����ζ�ŵ������м��Ԫ��
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


