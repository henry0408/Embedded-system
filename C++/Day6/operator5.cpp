#include <iostream>
using namespace std;

class Person
{
    int age;
    string name;
public:
    Person(int a):age(a){
        cout<<"����"<<endl;
    }
    Person(string name,int a):name(name),age(a)
    {}
    Person(const Person& o)
    {
        cout<<"����"<<endl;
    }
   void operator=(Person& other)
    {
        cout<<"=����"<<endl;
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

    Person p2(p);//�����¶��󣬿���
    p = p1;//�����Ѿ����ڵĶ��󣬵��ø�ֵ�����������

    p.show();
    p1.show();

    p = 100;
    p.show();

    return 0;
}