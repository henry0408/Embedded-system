/*
��ϰ.�Զ���һ����ʵ��ջ�ṹ���г�ջ��pop������ջ��push�����ܣ����Դ�����������

class MyStack

	1.��Ա����ָ��ָ������int* stack;

	2.��Ա������ʾ���鳤��length = 10

	4.��Ա������ʾջ��  top = 0

	3.��Ա����pop()��push(int data)

	5.��Աinit����Ա��������ʼֵ(index��length = 10����������)

6.	��Ա����expand(); �������飬����Ϊԭ�����������(���Բ���)

˼·��������ڵ��������ˣ�����һ����������飬��ԭ����������ݿ������µ�������*/
#include <iostream>
using namespace std;

class MyStack
{
private:
    int *stack;
    int length;
    int top;

public:
    void init(int t, int len);
    int pop();
    bool push(int data);
    void print_info();

    void expand();
};