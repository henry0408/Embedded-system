/*不同函数间调用*/

#include <stdio.h>

void f();
void g();
void k();

void f()
{
    printf("FFFFF\n");
    g();
    printf("11111\n");
}

void g()
{
    printf("GGGGGG\n");
    k();
    printf("222222\n");
}

void k()
{
    printf("KKKKKKK\n");
}

int main()
{
    f();
}

/*输出
FFFFF
GGGGGG
KKKKKKK
222222
11111
*/