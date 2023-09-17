/*构造函数的调用原则*/

#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        cout<<"default construct with elements"<<endl;
    }
    Person(int age)
    {
        m_age = age;
        cout<<"construct with elements"<<endl;
    }
    Person(const Person& p)
    {
        m_age = p.m_age;
        cout<<"copy construct with elements"<<endl;
    }
    ~Person()
    {
        cout<<"destruct"<<endl;
    }

    int m_age;
};

int main()
{
    Person p1;
    p1.m_age = 18;
    Person p2(p1);
    cout<<p2.m_age<<endl;
}