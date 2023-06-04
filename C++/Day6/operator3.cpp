#include <iostream>

using namespace std;

class Person
{
    string name;
    int age;
    
public:
    Person(string name, int age):name(name),age(age){}
    bool operator == (Person &p1);
    bool operator == (string s1);
    bool operator == (int a1);
};

bool Person::operator==(Person &p1)
{
    return this->age == p1.age;
}

bool Person::operator==(string s1)
{
    return this->name == s1;
}

bool Person::operator==(int a1)
{
    return this->age == a1;
}

int main()
{
    Person p1("aa",18);
    Person p2("bb",20);

    cout<<(p1==p2)<<endl;
    cout<<(p1=="aa")<<endl;
    cout<<(p1==20)<<endl;
    
}