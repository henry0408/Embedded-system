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
class B : public A
{
private:
    int num;
public:
    B(int money,int n):A(money),num(n)
    {
        cout<<"b create"<<endl;
        cout<<"b "<<num<<endl;//10
        cout<<"b: "<<this->money<<endl;//1
    }
};

class C : public A
{
public:
    C(int money):A(money)
    {
        cout<<"c create"<<endl;
        cout<<"c: "<<this->money<<endl;//3
    }
};
class D : public B,public C
{
public:
    D(int m):B(m-1,10),C(m+1)
    {
        cout<<C::money<<endl;// 3
        cout<<"D create"<<endl;
    }
};

int main()
{
    D d(2);
    return 0;
}