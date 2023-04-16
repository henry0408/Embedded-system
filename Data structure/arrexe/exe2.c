/*搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。请必须使用时间复杂度为 O(log n) 的算法*/

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