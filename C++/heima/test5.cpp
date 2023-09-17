#include <iostream>

using namespace std;

class Person
{
	int m_a;	//属于类的对象上
    int m_b;	//属于类的对象上
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