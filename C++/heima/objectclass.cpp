#include <iostream>

using namespace std;

class Phone
{
public:
    Phone(string pname):m_pname(pname)
    {
        cout<<"Phone gouzao"<<endl;
    }
    ~Phone()
    {
        cout<<"Phone xigou"<<endl;
    }

    string m_pname;
};

class Person
{
public:
    //Phone m_Phone = pName ÒþÊ½×ª»»
    Person(string name, string pName):m_name(name),m_phone(pName)
    {
        cout<<"person gouzao"<<endl;
    }
    ~Person()
    {
        cout<<"Person xigou"<<endl;
    }
    string m_name;
    Phone m_phone;
};

void test()
{
    Person p1("zhangsan","iphone");
    cout<<p1.m_name<< " " <<p1.m_phone.m_pname <<endl;
}

int main(int argc, char const *argv[])
{
    
    test();
    return 0;
}
