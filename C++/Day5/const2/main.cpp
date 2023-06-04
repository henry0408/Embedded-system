#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age)
    {}

    //常函数，不可以修改成员变量
    void show() const
    {
        cout<<age<<endl;
    }

    void setAge(int a)
    {
        age += a;
    }

};

int main()
{

    const Person p1(28);
    p1.show();
    //p1.setAge(2);       //使用时报错
    return 0;
}
