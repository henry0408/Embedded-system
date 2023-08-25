#include <stdio.h>

int func(int num)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag != 0)
    {
        if((num & flag) != 0)
        {
            count++;
        }
        flag = flag<<1;
    }
    return count;
}

int main()
{
    printf("%d\n",func(7));
}