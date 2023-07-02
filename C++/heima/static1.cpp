#include <iostream>

using namespace std;

class Person
{
private:
	
	//所有对象共享同一份
	static int m_A;
};

int Person::m_A = 10;

int main()
{
	//通过类名访问
	cout<<Person::m_A<<endl;	//报错
}