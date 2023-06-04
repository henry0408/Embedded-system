/*1.有个学生类Student 包括私有成员：姓名 成绩 ;  Student构造函数对成员赋值

*/


#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
    friend class Teacher;
private:
    string name;
    int score;

public:
    Student(string name, int score);
    ~Student();
};

#endif // STUDENT_H
