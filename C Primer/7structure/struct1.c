/*
结构体的声明方式：
*/

#include <stdio.h>

//方法1：
struct Student
{
    /* data */
    int age;
    float score;
    char sex;
};


//方法2：定义结构体的同时直接定义变量名（不好，因为这样只能定义一次）
struct Student2
{
    /* data */
    int age;
    float score;
    char sex;
} st2;


//方法3：不好
struct
{
    /* data */
    int age;
    float score;
    char sex;
} st3;


int main (void)
{
    struct Student st1 = {80, 12.5, 'M'}; //初始化，定义的同时赋值
    printf("age = %d, score = %f, sex = %c \n", st1.age, st1.score, st1.sex);

    struct Student st2;
    st2.age = 10;
    st2.score = 100;
    st2.sex = 'F';
    printf("age = %d, score = %f, sex = %c \n", st2.age, st2.score, st2.sex);

    return 0;
}