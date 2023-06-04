#include <iostream>
using namespace std;

class Person
{
    int age;
    string name;
public:
    Person(int a):age(a){
        cout<<"构造"<<endl;
    }
    Person(string name,int a):name(name),age(a)
    {}
    Person(const Person& o)
    {
        cout<<"拷贝"<<endl;
    }
   void operator=(Person& other)
    {
        cout<<"=重载"<<endl;
        this->age = other.age;
    }
   void operator =(int a)
   {
       cout<<"int..."<<endl;
       this->age = a;
   }
   void show()
   {
       cout<<age<<endl;
   }
};
int main()
{
    Person p(10);
    Person p1(20);

    Person p2(p);//创建新对象，拷贝
    p = p1;//两个已经存在的对象，调用赋值运算符的重载

    p.show();
    p1.show();

    p = 100;
    p.show();

    return 0;
}