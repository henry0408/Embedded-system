/*
 *分文件写
1、Student类
1.私有成员score，name
2.公有构造函数传入score，name
3.公有函数setScore给score赋值
4.公有函数show显示成绩和名字

 *
 */


#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
#include <string>
#include <iostream>

class Student
{
private:
    int score;
    string name;
public:
    Student(int score, string name);

    void setScore(int score);

    void show();

    ~Student();
};

#endif // STUDENT_H
