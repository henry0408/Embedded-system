#include <iostream>

using namespace std;

class Person
{
private:
	
	//���ж�����ͬһ��
	static int m_A;
};

int Person::m_A = 10;

int main()
{
	//ͨ����������
	cout<<Person::m_A<<endl;	//����
}