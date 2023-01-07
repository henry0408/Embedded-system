# include <stdio.h>

int global_var = 100;

int f(int num)
{
    num = num + 1;
    return num;
}

int g(int num)
{
    return f(num);
}

int main (void)
{
    printf("%d\n", g(global_var));

    return 0;
}