/*
��ϰ5�����캯������ʱ�� show������ʾ ����ʱ�����һ�� MyTimer  ���ļ�д���ó�ʼ���б�

�������11 32 41     --��11 32 42

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