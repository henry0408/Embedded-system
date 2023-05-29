#include <iostream>

using namespace std;

class Person
{
private:
    int age;
public:
    Person()
    {
        age = 18;
        cout<<"create1"<<endl;
    }
    Person(int a)
    {
        age = a;
        cout<<"create2"<<endl;
    }
    void show()
    {
        cout<<age<<endl;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Person *p = new Person();
    p->show();

    Person *p1 = new Person(30);
    p1->show();

    Person p3;
    p3.show();

    Person p4(40);
    p4.show();

    return 0;
}
