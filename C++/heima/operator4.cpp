#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout<< myint.m_Num;
	return cout;
}

void test()
{
	MyInteger myint;
	
	cout << myint << endl;
}

int main()
{
	test();
}