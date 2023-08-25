#include <iostream>

using namespace std;

class Person
{
public:
	
	//所有对象共享同一份
	static int m_A;
};

//类外初始化
int Person::m_A = 100;

int main()
{
	Person p;
	cout<<p.m_A<<endl;
	
	Person p2;
	p2.m_A = 200;
	
	cout<<p.m_A<<endl;
}