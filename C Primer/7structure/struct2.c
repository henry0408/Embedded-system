/*如何取出结构体中的每一个变量

pst->age 会被转换成 (*pst).age
*/


#include <stdio.h>

struct Student
{
    /* data */
    int age;
    float score;
    char sex;
};


int main (void)
{
    struct Student st1 = {80, 12.5, 'M'}; //初始化，定义的同时赋值
    printf("age = %d, score = %f, sex = %c \n", st1.age, st1.score, st1.sex);//第一种取出变量的方式

    struct Student * pst = &st1;
    pst ->age = 88; //第二种取出变量的方式

    printf("age = %d, score = %f, sex = %c \n", st1.age, st1.score, st1.sex);

    return 0;
}





