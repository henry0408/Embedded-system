#include <stdio.h>

int main(void)
{
        char ch1, ch2;
        ch1 = getchar();
        ch2 = getchar();
        printf("%d  %d\n", ch1, ch2);

        return 0;
}

/*
如果只输入一个字符并按下回车，会出现两个数字，第一个数字为char-->int的结果，第二个为回车符的int
*/