#include <iostream>

using namespace std;

class Base
{
public:
	virtual void func() = 0;
};

class Son : public Base
{
public:
	void func()
	{
		cout<<"func"<<endl;
	}
};

void test1()
{
	Base *base = new Son;
	base->func();
}

int main()
{
	test1();
}