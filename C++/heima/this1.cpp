#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}
	
	Person& PersonAddAge(Person p)	//Ҫ���ر��壬��������������
	{
		this->age += p.age;
		return *this;		//����һ����
	}
	
	int age;
};

void test()
{
	Person p1(10);
	Person p2(10);
    
	p2.PersonAddAge(p1).PersonAddAge(p1);	//��ʽ���
	cout<<"age of p2: "<<p2.age<<endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
