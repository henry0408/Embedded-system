#include <iostream>

using namespace std;

class Baby
{
public:
    virtual void show(int a) = 0;
    //基类中不实现，必须在派生类中实现

    //virtual void print(int a) = 0;  //多个抽象函数，子类需要全部重写才能变成不是抽象类
};

class Student : public Baby
{
public:
    void show(int a)
    {
        cout<<a<<endl;
    }
};

int main()
{
    //Baby b;     //包含纯虚函数的类叫做抽象类（接口），不能在类外实例化对象
    Student s;
    s.show(10);

    Baby *b = new Student;
    b->show(20);
    return 0;
}

