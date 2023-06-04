#include <iostream>

using namespace std;

class Person
{
    mutable int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {
        age++;
        cout<<age<<endl;
    }
    //普通函数
    void show()
    {
        age++;
        cout<<age<<endl;
    }

};

int main()
{
    Person p(18);
    p.show();

    const Person p1(18);
    p1.show();
    return 0;
}
