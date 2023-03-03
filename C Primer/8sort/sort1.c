/*冒泡排序
每一次，数组中的相邻两位相比较（i.e. 0-1, 1-2, 2-3, 3-4, ...)，大的放在右边，小的放在左边;
每一次，最右侧的都是最大的
所以一共需要len-1次；每一次中又需要len-1-i次迭代
*/

# include <stdio.h>

void sort (int *a, int len)
{
    int i, j, t;
    for (i = 0; i < len-1; i++)
    {
        for (j = 0; j < len-1-i; j++)
        {
            if(a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
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