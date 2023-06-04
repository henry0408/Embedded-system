/*2.设计一个友元类Teacher
    1)teacher类中包含 私有成员数组 Student s[5]; 构造函数对数组元素赋值
    2)teacher类对学生数组进行排序  公有成员函数sort(); 降序 冒泡排序
    3)teacher类输出成绩对应等级  公有函数show();
>=90 优 80-89 良  70-79中 60-69 及格  <60不及格
*/


#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"

using namespace std;

class Teacher
{
private:
    Student *s[5];
public:
    Teacher()
    {
        s[0] = new Student("aa",90);
        s[1]= new Student("bb",80);
        s[2]= new Student("cc",70);
        s[3]= new Student("ddd",100);
        s[4]= new Student("eeee",95);
    }

    void swap(Student &a, Student &b);

    void sort();

    void show();

    ~Teacher();
};

#endif // TEACHER_H
