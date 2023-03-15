/* 插入排序

左侧为已排序数组，右侧未排序

当前排完序的最后（最右）一个元素为i，那么i+1就是下一个需要拿出来的元素arr[i+1]

拿出来的元素，和之前的所有元素（左边）排序：
j从0开始，到当前元素的index（i+1）

如果当前元素的值在arr[j]和arr[j+1]之间，则插入

arr[j+1]之后所有的值向后移一位
arr[i+1]的值变成arr[j+1]的值

*/

#include <stdio.h>

void sort(int * arr, int len)
{
    int key;
    for (int i = 1; i < len; i++)     //当前排完序的最后（最右）一个元素为i，那么i+1就是下一个需要拿出来的元素arr[i+1]，但我们直接从index = 1开始
    {
        key = arr[i];                   //拿出来的数字叫做key
        int j;
        for (j = i-1; j >= 0; j--)    //拿出来的元素，和之前的所有元素（左边）排序，j的目的是记录当前数字最后需要插入到哪（最后的index）：
        {
            if(key < arr[j]){           //如果key比已排序数组最右侧的数字小，则所有右侧的数字向右移一位
               arr[j+1] = arr[j];
            }
            else{                       //如果key比已排序数组最右侧的数字还要大，那么直接退出循环
                break;
            } 
        }
        arr[j+1] = key;
    }
}


int main (void)
{
    int a[6] = {2, -8, 10, 8, 9, -1};
    sort(a,6);

    for (int i = 0; i<6; i++){
        printf("%d ",a[i]);
    }

    return 0;
}