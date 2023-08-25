#include <iostream>

using namespace std;

class Base
{
public:
	void func()
	{
		cout<<"Base func"<<endl;
	}
	
	void func(int num)
	{
		cout<<"Base func num"<<endl;
	}
};

class Son: public Base
{
public:
	void func()
	{
		cout<<"Son func"<<endl;
	}
};

int main()
{
	Son s;
	s.func();
    //s.func(100);    //±¨´í
}