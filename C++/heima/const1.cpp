#include <iostream>

using namespace std;

class Person
{
public:
    Person(int a, int b):m_A(a),m_B(b){}

    int m_A;
	mutable int m_B;	//�ӹؼ���

	void showPerson() const
	{
		m_B = 200;		//�����޸�
	}
	
	void func()
	{
		m_A= 200;
	}
	
	
};

void test()
{
	const Person p(10,20);
	//p.m_A = 100;	//����
	p.m_B = 300;	//�����޸�
	
	p.showPerson();
    cout<<p.m_B<<endl;
	//p.func();		//����
}

int main()
{
    test();
}