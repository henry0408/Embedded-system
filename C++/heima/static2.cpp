#include <iostream>

using namespace std;

class Person
{
public:
	
	//���ж�����ͬһ��
	static int m_A;
};

//�����ʼ��
int Person::m_A = 100;

int main()
{
	Person p;
	cout<<p.m_A<<endl;
	
	Person p2;
	p2.m_A = 200;
	
	cout<<p.m_A<<endl;
}