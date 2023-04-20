#include <stdio.h>
int findRepeatNumber(int*arr, int len)
{
	int i = 0;
	while(i<len)
	{
		if(arr[arr[i]] == arr[i])
		{
			return arr[i];
		}
		else
		{
			if(arr[i] == i)
            {
                i++;
                continue;
            }
            else
            {
            	int temp = arr[i];
            	arr[i] = arr[temp];
            	arr[temp] = temp;
            }
		}
	}
	printf("no repeated num\n");
	return -1;
}

int main()
{
    int arr[10] = {3,8,2,1,4,5,6,7,8,9};
    int ans;
    ans = findRepeatNumber(arr, 10);

    printf("%d\n", ans);

    return 0;
}