/*
因为a是一个指针变量，所以a[i] == *(a+i) 
*/


# include <stdio.h>

int main(void)
{
	int a[5] = {1,2,3,4,5};
	int i;

	for (i=0; i<5; ++i)
		// printf("%d\n", a[i]);  //a[i] == *(a+i) 
        printf("%d\n", *(a+i));  //a[i] == *(a+i) 

	return 0;
}