/*
 *��ϰ6�������˿���Poker��˽������color��point������54���ƴ���������
            ��С����������ֻ�л�ɫ��û�з�ֵ
            1.���캯������ʼ����ɫ�͵�������ͨ���ƣ�
            2.���캯������ʼ����ɫ����/С����
            3.��Ա���� toString();��ʾ54���� ��������2  ����A

            4.main �������飬54������ָ��  p�� = new Poker("��Ƭ","A");
                                            p ��= new Poker("����");
                    ���54����

string colors[4] = {"����", "����", "��Ƭ", "�ݻ�"};
string points[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
 */



#ifndef POCKER_H
#define POCKER_H

#include <iostream>
using std::string;

class Pocker
{
private:
    string point;
    string color;
public:
    Pocker(string p, string c);
    Pocker(string c);
    string toString();
};

#endif // POCKER_H
