#include <iostream>

using namespace std;

class Person
{
	static int m_a;	//��̬��Ա��������������Ķ�����
};

int Person::m_a = 0;

void test()
{
	Person p;
	cout<<"sizeof p is "<< sizeof(p)<<endl;	//1
}

int main()
{
	test();
}