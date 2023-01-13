/*多级指针2*/

#include <stdio.h>

void f (int **q)
{
    //*q就是p
    int i = 10;
    *q = &i;
}

void g (void)
{
    int i = 5;
    int *p = &i;
    printf("The value of *p is %d\n", *p);
    f(&p);
    printf("The value of *p is %d\n", *p);

}

int main (void)
{

    g();
    return 0;
}