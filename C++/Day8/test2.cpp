#include <iostream>

using namespace std;

class A
{
    int age;
public:
    A()
    {
        age = 18;
        cout<<"hello1"<<endl;
    }

    A(int a = 18)
    {
        age = a;
        cout<<"hello2"<<endl;
    }

    void show()
    {
        cout<<age<<endl;
    }
};




int main()
{
    A* a = new A();
    a->show();
}