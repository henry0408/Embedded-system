#include <iostream>
#include <map>

using namespace std;

class Person
{
    string name;
public:
    Person(const char* name):name(name){}
    void show() const 
    {
        cout<<name<<endl;
    }
    bool operator <(const Person& o) const  //����Ҫ��const����Ϊ���������ʱ������const Person& o����mapҪ������������е�Person������constant
    {
        if(this->name < o.name)
            return true;
        else
            return false;
    }
};

int main()
{
    map<Person,int> m;
    Person p("xm");
    m.insert(pair<Person,int>(p,1));

    m.insert(pair<Person,int>(Person("tom"),2));    //����

    m.insert(pair<Person,int>("jack",1));           //��ʽ

    m["rose"] = 4;

    for(map<Person,int>::iterator it = m.begin(); it!=m.end();it++)
    {
        it->first.show();
        cout<<it->second<<endl;
    }

    //����
    map<Person,int>::iterator iter = m.find(Person("rose"));
   
}