/*
 *2、Teacher类
1.Student* students[3];私有数组保存学生对象
2.公有构造函数，给students数组赋值  创建三个学生对象
3.公有函数 Student* randHappyBoy()随机抽取一个学生指针
4.公有函数hehe(Student*)将随机抽取的这个学生改为0分
5.公有函数teacherShow()显示最终的所有学生成绩 三个学生的成绩
cstdlib  ctime  srand(time(0))     rand()%3
 */


#ifndef TEACHER_H
#define TEACHER_H

# include <string>
# include <ctime>
# include <cstdlib>
# include "student.h"
using namespace std;

class Teacher
{
private:
    Student* students[3];
public:
    Teacher(Student* s[]);

    Student* randHappy();

    void hehe(Student *s);
    void show();

    ~Teacher();
};

#endif // TEACHER_H
