/*多个switch嵌套中break的使用：
break只会终止最近的switch
*/

# include <stdio.h>

int main()
{ 
	int x=1, y=0, a=0, b=0;
	switch(x) // 
	{  
	case 1:  
		switch(y)  // 
		{  
		case 0:  
			a++; 
			break; // 
		case 1:  
			b++; 
			break;
		}
		b = 100; //发现最后b不是0，而是100，说明break只终止了内部的switch
		break;   
	case 2: 
		a++;    
		b++;
		break;  
	}	
	printf("%d %d\n",a,b); //
	
	return 0;
}
