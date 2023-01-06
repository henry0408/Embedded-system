# include <stdio.h>

int main(void)
{
    int  i=0, s=0;
	
	do
	{ 
		if(i%2)
		{
			printf("yes, ");
            i++;
            printf("i = %d, ", i);
            printf("s = %d \n", s);
			continue;
		}
        printf("no, ");
		i++;
		s+=i; 
        printf("i = %d, ", i);
        printf("s = %d \n", s);
	}while(i < 5); 
	
	printf("%d\n",s);   
	
	return 0;
}
