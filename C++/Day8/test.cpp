#include <iostream>

using namespace std;


class C
{
public:
    C()
    {
        cout<<"C create"<<endl;
    }
    ~C()
    {
        cout<<"C delete"<<endl;
    }
};


class B
{
public:
    B()
    {
        cout<<"B create"<<endl;
    }
    ~B()
    {
        cout<<"B delete"<<endl;
    }
};

class A
{
public:
    A()
    {
        cout<<"A create"<<endl;
    }
    ~A()
    {
        cout<<"A delete"<<endl;
    }
};

class D
{
public:
    D()
    {
        cout<<"D create"<<endl;
    }
    ~D()
    {
        cout<<"D delete"<<endl;
    }
};

C c;
int main()
{
    A* a = new A;
    B b;
    static D d;
    delete a;
}