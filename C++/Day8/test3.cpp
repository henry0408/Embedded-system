#include <iostream>

using namespace std;

class A
{
public:
    A(int a)
    {
        cout<<"create"<<endl;
    }
    A(const A& other)
    {
        cout<<"copy"<<endl;
    }
};

int main()
{
    A a1 = A(10);   //显式有参构造
    A a2 = A(a1);

    A a3 = 10;      //隐式法
    A a4 = a3;

    A a5(a4);
}