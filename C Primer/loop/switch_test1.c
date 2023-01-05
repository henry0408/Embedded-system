/*switch一旦找到程序的入口之后，就会按顺序执行下面的case*/

#include <stdio.h>

int main (void)
{
    int val;

    printf("Please enter your floor: ");
    scanf("%d", &val);
    
    switch (val)
    {
    case 1:
        printf("The first floor\n");
        // break; // 注释掉break后会发现前两个case都运行

    case 2:
        printf("The second floor\n");
        break;

    case 3:
        printf("The third floor\n");
        break;
    
    default:
        break;
    }

    return 0;
}