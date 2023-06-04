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
    int operator +(const Person& o)
    {

        return this->age + o.age;
    }
    bool operator ==(const Person &o)
    {
        return this->age == o.age;
    }

     bool operator >=(const Person &o);
};

bool Person::operator >=(const Person &o)
{
    return this->age >= o.age;
}

int main()
{
    Person p(18);
    Person p1(20);

    cout<<(p+p1)<<endl; //38
    cout<<(p == p1)<<endl;  //0

    cout<<2+3<<endl;
}

