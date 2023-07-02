#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age){}
    void show()
    {
        cout<<age<<endl;
    }
    Person& operator +(const Person& o)
    {
        this->age += o.age;
        return *this;
    }
};

//全局运算符重载


template <typename T>

T& sum(T& a, T& b)
{
    return a+b;
}

int main()
{
    Person p(20);
    Person p1(30);

    sum<Person>(p,p1).show();

}