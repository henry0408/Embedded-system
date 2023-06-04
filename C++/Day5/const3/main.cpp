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
    return 0;
}
