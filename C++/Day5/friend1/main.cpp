#include <iostream>

using namespace std;

class Person
{
    friend void display(Person& p);     //友元函数声明
private:
    int age;
public:
    Person(int age):age(age){}
    void show()
    {
        cout<<age<<endl;
    }
};


//全局函数
void display(Person& p)
{
    cout<<p.age<<endl;
}


int main()
{
    Person p(10);
    display(p);
    return 0;
}

