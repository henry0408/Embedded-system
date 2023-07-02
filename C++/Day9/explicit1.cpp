#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
    int age;
    string name;
public:
    Person(int age);
    Person(const char* name);       //不能写成string
    Person(int age, const char* name);      //不能发生隐式转换
    // Person(int age, const char* name = "xm");

    ~Person();
    void show();
};

// Person::Person(int age)
// {
//     this->age = age;
//     cout<<"create"<<endl;
// }

Person::Person(const char* name)        
{
    this->name = name;
    cout<<"create name"<<endl;
}

Person::Person(int age, const char* name)        
{
    this->age = age;
    this->name = name;
    cout<<"create age and name"<<endl;
}

Person::Person(int age, const char* name = "xm")        
{
    this->age = age;
    // this->name = name;
    cout<<"create age and name"<<endl;
}

void Person::show()
{
    cout<<age<<endl;
}

Person::~Person()
{
}

int main(int argc, char const *argv[])
{
    /* code */
    Person p(19);
    p.show();

    Person p1 = 28;     //隐式转换
    p1.show();

    Person p2 = "xm";   //隐式转换
    p2.show();

    return 0;
}

