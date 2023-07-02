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
    bool operator <(const Person& o) const  //都需要加const是因为运算符重载时声明的const Person& o，而map要求运算符重载中的Person必须是constant
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

    m.insert(pair<Person,int>(Person("tom"),2));    //匿名

    m.insert(pair<Person,int>("jack",1));           //隐式

    m["rose"] = 4;

    for(map<Person,int>::iterator it = m.begin(); it!=m.end();it++)
    {
        it->first.show();
        cout<<it->second<<endl;
    }

    //查找
    map<Person,int>::iterator iter = m.find(Person("rose"));
   
}