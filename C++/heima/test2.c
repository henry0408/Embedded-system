#include <stdio.h>

int func(int x)
{
	int countx = 0;
	while(x)
	{
		countx ++;
		x = x&(x-1);

        printf("%d\n",x);
	}
	return countx;
}

int main()
{
    int a = func(9999);
    printf("%d\n",a);
}