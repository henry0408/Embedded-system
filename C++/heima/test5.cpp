#include <iostream>

using namespace std;

class Person
{
	int m_a;	//������Ķ�����
    int m_b;	//������Ķ�����
};

void test()
{
	Person p;
	cout<<"sizeof p is "<< sizeof(p)<<endl;	//4
}

int main()
{
	test();
}