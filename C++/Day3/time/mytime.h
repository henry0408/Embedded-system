/*
练习5：构造函数传入时间 show函数显示 输入时间的下一秒 MyTimer  分文件写！用初始化列表

如果输入11 32 41     --》11 32 42

            23  59  59  -->  0   0  0 
*/

#ifndef TIME
#define TIME

#include <iostream>
using namespace std;

class MyTimer
{
private:
    int hour;
    int minute;
    int second;
public:
    MyTimer(int h, int m, int s);

    void getTime();
};

#endif