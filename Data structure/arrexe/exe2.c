/*��������λ��
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á������ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨*/

void find_pos(int*arr, int num, int length)
{
    int left = 0, right = length, mid;
    while(left <= right)
    {
        mid = (left+right)/2;
        if(arr[mid] > num)
        {
            right = mid-1;
        }
        else if(arr[mid] < num)
        {
            left = mid+1;
        }
        else
        {

        }
    }
}


int main()
{
    int arr[10] = {1, 3, 4, 5, 7, 21, 21, 21, 30, 32};
    int num = 21;
    find_pos(arr,num, 10);
}