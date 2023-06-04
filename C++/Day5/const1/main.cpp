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
        //age++;              //error
        //setAge(1);              //error
        cout<<age<<endl;
    }

    void setAge(int a)
    {
        age += a;
    }

};

int main()
{
    Person p(18);
    p.show();
    return 0;
}

