/*手动建立一个数组*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr
{
    int *pBase;     //第一个元素
    int len;        //能容纳的最大元素个数（用于内存分配）
    int cnt;        //当前数组有效元素个数
};

void init_arr(struct Arr * pArr, int length);

bool is_empty(struct Arr *pArr);        //有效个数为0则为空

bool is_full(struct Arr *pArr);

void show_arr(struct Arr * pArr);

bool append_arr(struct Arr *pArr, int num);

bool insert_arr(struct Arr *pArr, int pos, int num);    //pos值从1开始（下标为0为第一个元素）

bool delete_arr(struct Arr *pArr, int pos, int * pVal);             //pos从1开始，删除之后还可以返回删除的值

void reverse_arr(struct Arr *pArr);                     //倒置数组

void sort_arr(struct Arr *pArr);
//int get();

int main (void)
{
    struct Arr arr;
    init_arr(&arr, 6);     //注意：只能传地址
    
    show_arr(&arr);         //注意：可以直接传arr，但不好
    append_arr(&arr, 8);
    append_arr(&arr, 2);
    append_arr(&arr, 13);
    append_arr(&arr, -1);
    append_arr(&arr, -3);
    append_arr(&arr, 9);
    show_arr(&arr);

    insert_arr(&arr, 1, 99);
    show_arr(&arr);

    int val;        //用于存放删除的元素的数值        
    delete_arr(&arr, 1, &val);
    printf("The num you delete is %d\n",val);
    show_arr(&arr);

    reverse_arr(&arr);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);
    
    return 0;
}

void init_arr(struct Arr * pArr, int length)
{
    pArr->pBase = (int*)malloc(sizeof(int)*length);
    if (pArr->pBase == NULL)            //如果分配失败
    {
        printf("Fail to allocate\n");
        exit(-1);                       //终止整个程序
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}

bool is_empty(struct Arr *pArr)
{
    if (pArr->cnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool is_full(struct Arr *pArr)
{
    if(pArr ->cnt == pArr ->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void show_arr(struct Arr * pArr)
{
    if(is_empty(pArr))          //如果为空
    {
        printf("Is empty\n");
    }
    else
    {
        for (int i = 0; i<pArr->cnt; i++)
        {
            printf("%d ",pArr->pBase[i]);    //重点！！！！
        }
        printf("\n");
    }
    return;
}

bool append_arr(struct Arr *pArr, int num)
{
    if(is_full(pArr))       //满了
    {
        return false;
    }
    else
    {
        pArr->pBase[pArr->cnt] = num;
        (pArr->cnt) ++;
        return true;
    }
}

bool insert_arr(struct Arr *pArr, int pos, int val)     //pos为插入的位置（第pos个index），其他所有元素向后移一位
{
    if(is_full(pArr))
    {
        return false;
    }
    if(pos<1 || pos >pArr->cnt+1)
    {
        return false;
    }
    
    for (int i = (pArr->cnt) -1; i>=pos-1; i--)
    {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    (pArr->cnt)++;
    return true;
}

bool delete_arr(struct Arr *pArr, int pos, int * pVal)
{
    if(is_empty(pArr))
    {
        return false;
    }

    if(pos<1 || pos>pArr->cnt)
    {
        return false;
    }

    *pVal = pArr->pBase[pos-1];
    for (int i = pos; i<pArr->cnt; i++)         //删除的元素后面的所有元素向前移一位
    {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt --;
    return true;
}


void reverse_arr(struct Arr *pArr)          //倒置一个数组，前半部分元素和后半部分元素一一替换
{
    int temp;
    for (int i = 0; i< (pArr->cnt)/2; i++)
    {
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[pArr->cnt-i-1];
        pArr->pBase[pArr->cnt-i-1] = temp;
    }
    return;
}


void sort_arr(struct Arr *pArr)                 //冒泡排序
{
    int temp;
    for (int i = 0; i<pArr->cnt-1; i++)
    {
        for (int j = 0; j<pArr->cnt-1-i; j++)
        {
            if (pArr->pBase[j] > pArr->pBase[j+1])
            {
                temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[j+1];
                pArr->pBase[j+1] = temp;
            }
        }
    }
    return;
}
