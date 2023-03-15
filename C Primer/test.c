#include <stdio.h>

int main (void)
{
    // int i;
    // for (i = 1; i <= 4; i++){
    //     printf("%d\n", i);
    // }
    // printf("The final value of i is: %d\n", i);

    // int i;
    // for (i = 2; i <= 3; i++){
    //     printf("%d\n", i);
    //     if (i == 3){
    //         break;
    //     }
    // }
    // printf("The final value of i is: %d\n", i);

    // int a = 5;
    // printf("%d",a);


    // if (a&2 == 0)
    // {
    //     printf("ok");
    // }


    // int a[5] = {1,2,3,4,5};
    // for (int i = 0; i < 5; i++)     //当前排完序的最后（最右）一个元素为i，那么i+1就是下一个需要拿出来的元素arr[i+1]
    // {
    //     printf("%d\n", a[i]);
    // }

    
	// printf("%d\n", sizeof(int));
    // printf("%d\n", sizeof(short));
    // printf("%d\n", sizeof(long));
    // printf("%d\n", sizeof(double));
    // printf("%d\n", sizeof(float));

    // int x = 4;
    // int y;
    // y = ++x;

    // int x = 5;
    // int y = 9;
    // int z;
    // z = ++x + y++;

    // printf("x is %d, y is %d, z is %d\n", x, y, z);

    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    int max;
    max = a;
    if (b>max)
    {
       max = b;
    }
    if (c>max)
    {
       max = c;
    }

    printf("max is %d\n", max);

    return 0;
}