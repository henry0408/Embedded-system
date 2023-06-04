#include <iostream>

using namespace std;

class A
{
protected:
    int money;
public:
    A(int money):money(money){
        cout<<"A create"<<endl;
    }
};


class B:virtual public A
{

public:
    B(int money):A(money){
        cout<<"B create"<<"B money is: "<<this->money<<endl;
    }
};


class C:virtual public A
{

public:
    C(int money):A(money){
        cout<<"C create"<<"C money is: "<<this->money<<endl;
    }
};


class D: public B,public C
{

public:
    D(int money):A(money),B(money),C(money){
        cout<<"D create"<<endl;
    }

    void show()
    {
        cout<<B::money<<" "<<C::money<<" "<<this->money<<endl;
    }
};


int main()
{
    D d(20);
    d.show();
    return 0;
}

