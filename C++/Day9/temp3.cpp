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
};

template <typename T, class U>
T div(T a, T b, class c)
{
    c.show();
    return a/b;
}

int main(int argc, char const *argv[])
{
    /* code */
    Person p(19);
    div<int, Person>(10,2,p);
    div<int, Person>(10,2,Person(20));  //匿名对象
    div<int, Person>(10,2,30);          //隐式      
    return 0;
}   
