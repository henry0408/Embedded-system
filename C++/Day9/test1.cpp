#include <iostream>

using namespace std;

class A
{
protected:
	int money;
public:
	A(int money):money(money)
	{
		cout<<"a create"<<endl;
	}
};

class B: virtual public A
{
public:
	B(int money):A(money)
	{
		cout<<"b create"<<endl;
	}
};

class C: virtual public A
{
public:
	C(int money):A(money)
	{
		cout<<"c create"<<endl;
	}
};

class D:public B, public C
{
public:
	D(int money):A(money),B(money),C(money)
	{
		cout<<"d create"<<endl;
	}
    void show()
    {
        cout<<money<<endl;
    }
};

int main()
{
    D d(200);
    d.show();
}