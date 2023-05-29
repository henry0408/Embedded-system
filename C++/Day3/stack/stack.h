/*
练习.自定义一个类实现栈结构，有出栈（pop）和入栈（push）功能，可以存放任意多整数

class MyStack

	1.成员变量指针指向数组int* stack;

	2.成员变量表示数组长度length = 10

	4.成员变量表示栈针  top = 0

	3.成员函数pop()和push(int data)

	5.成员init给成员变量赋初始值(index，length = 10，创建数组)

6.	成员函数expand(); 扩充数组，扩充为原数组二倍长度(可以不做)

思路：如果现在的数组满了，创建一个更大的数组，将原来数组的数据拷贝到新的数组中*/
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