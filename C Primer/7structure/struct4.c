#include <stdio.h>
#include <string.h>

struct Student
{
    /* data */
    int sid;
    char name[100];
    int age;
};

void f(struct Student * st)         //��ֵ:��Ϊ����������һ��ָ�룬����ֱ�Ӹ�ֵҪ��->age������.age ;���ĳ�*()������һ��ֵ�����Կ�����.age
{
    st->age = 10; 
    //strcpy(st->name,"chen");
    strcpy((*st).name, "chen");

    (*st).sid = 200;
}

void g(struct Student st)           //���:��������д�����ǲ��ã�ռ���ڴ�ռ�
{
    printf("%d\n",st.sid);
    printf("%s\n",st.name);
    printf("%d\n",st.age);
}


//g�������õķ��������ݽ���һ���ṹ��ĵ�ַ: ��Զ4�ֽ�
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

