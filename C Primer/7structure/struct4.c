#include <stdio.h>
#include <string.h>

struct Student
{
    /* data */
    int sid;
    char name[100];
    int age;
};

void f(struct Student * st)         //赋值:因为传进来的是一个指针，所以直接赋值要用->age而不是.age ;若改成*()，则变成一个值，所以可以用.age
{
    st->age = 10; 
    //strcpy(st->name,"chen");
    strcpy((*st).name, "chen");

    (*st).sid = 200;
}

void g(struct Student st)           //输出:可以这样写，但是不好：占用内存空间
{
    printf("%d\n",st.sid);
    printf("%s\n",st.name);
    printf("%d\n",st.age);
}


//g函数更好的方法：传递进来一个结构体的地址: 永远4字节
void g2(struct Student *st)
{
    printf("%d\n",st->sid);
    printf("%s\n",st->name);
    printf("%d\n",st->age);
}

int main (void)
{
    struct Student st1 = {100, "hangyu", 20};
    f(&st1);
    // printf("%d\n",st1.sid);
    // printf("%s\n",st1.name);
    g(st1);

    g2(&st1);

    return 0;
}

