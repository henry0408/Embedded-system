/*
连续输入两次
*/


#include <stdio.h>

int main (void)
{
    int i,j;

    scanf("%d",&i);

    printf("The number i is %d\n", i);

    //下面四行代码用于避免错误
    // char ch;
    // while ((ch = getchar()) != '\n'){
    //     continue;
    // }

    scanf("%d",&j);

    printf("The number j is %d\n", j);
    
    return 0;
}

/*
会发现如果输入123m后，i可以正确读取123，但j由于读取的是m（对于输出%d来说不合法），所以出现的是乱码
*/