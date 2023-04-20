/*

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<4; j++)
        {
            printf("%d ", *(p+4*i+j));
        }
        printf("\n");
    }
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5][5] = 
    {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 14;

    int new_arr[25];
    int *p = &arr[0][0];
    for(int i=0; i<25; i++)
    {
        new_arr[i] = *(p+i);
    }

    for(int i=0; i<25; i++)
    {
        printf("%d ",new_arr[i]);
    }

    for(int i = 0; i<25-1;i++)
    {
        for(int j=0; j<25-1-i; j++)
        {
            if(new_arr[j]>new_arr[j+1])
            {
                int swap = new_arr[j];
                new_arr[j] = new_arr[j+1];
                new_arr[j+1] = swap;
            }
        }
    }

    int left = 0;
    int right = 25-1;

    while(left<right)
    {
        int mid = (left+right)/2;
        printf("mid is %d\n",new_arr[mid]);

        if(new_arr[mid] > target)
        {
            right = mid-1;
        }
        else if(new_arr[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            printf("Find! The val is %d\n",new_arr[mid]);
            exit(-1);
        }
    }
    printf("Not found\n");
}