#include <stdio.h>

void QkSort(int *arr, int left, int right){
    if (left > right)  //左指针位置必须大于右指针位置
    {
        return;
    }
    //变量tmp为基准数，在此规定基准数为序列的第一个数，即左指针指向的数
    int tmp = arr[left];
    int i = left; //左指针
    int j = right;   //右指针
    //外循环，直到左指针和右指针相等时退出，表示根据当前基准数以完成当前序列排序
    while (i != j)
    {   //内循环1，寻找到比基准数小的数时退出循环，此循环控制右指针    
        while (arr[j] >= tmp && j > i)
        {
            j--;
        }
        //内循环2，寻找到比基准数大的数时退出循环，此循环控制左指针
        while (arr[i] <= tmp && j > i)
        {
            i++;
        }
        //经过以上两个内循环后，此时的左指针和右指针分别指向了
        //比基准数小和比基准数大的数
        //接下来要将这两个指针的数据进行交换
        if (j > i)//交换前判断右指针是否大于左指针
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }//外循环尾

    //执行完循环后，就找到了基准数的排序位置，将基准数tmp与i位置进行交换
    arr[left] = arr[i];
    arr[i] = tmp;
    //*********************************************
    //下面的程序为递归，可能存在多层递归调用
    //*********************************************
    //此时的数组分为了两部分，基准数左边都是小于基准数的，右边都是大于基准数的，
    //现在进行递归，对基准数左边的数进行排序，此时递归可能会有多层
    QkSort(arr, left, i - 1);
    //进行到这步时，基准数左边已经全部有序，而右边还未进行排序，
    //现在进行递归，对基准数右边的数据进行排序，此时递归可能有多层
    QkSort(arr, i + 1, right);
}



int main()
{
    int a[] = {12,3,5,9,11,34,23};

    for(int i = 0; i<sizeof(a)/sizeof(int);i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    QkSort(a,0,sizeof(a)/sizeof(int)-1);

    for(int i = 0; i<sizeof(a)/sizeof(int);i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}