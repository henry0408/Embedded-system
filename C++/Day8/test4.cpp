#include <iostream>
using namespace std;

class Person
{
public:
    //Ðéº¯Êý£ºvirtual
    virtual void show()
    {
        cout<<"person  show..."<<endl;
    }
};
class Student : public Person
{
public:
    void show()
    {
        cout<<"stu  show..."<<endl;
    }
};
int main()
{
    Person p;
    p.show();
    Student stu;
    stu.show();

    return 0;
}