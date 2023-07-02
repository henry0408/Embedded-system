#include <iostream>
#include <map>

using namespace std;

class Person
{
    string name;
    int age;
public:
    Person(string name, int age):name(name),age(age){}
    bool operator <(const Person& o) const 
    {
        if(this->name < o.name || this->age < o.age)
            return true;
        else
            return false;
    }
    void show() const
    {
        cout<<name<<" "<<age<<endl;
    }
};

class Score
{
    int cpp;
    int c;
    int linux;
public:
    Score(int cpp, int c, int linux):cpp(cpp),c(c),linux(linux){}
    void show()
    {
        cout<<cpp<<" "<<c<<" "<<linux<<endl;
    }
};

int main()
{
    map <Person,Score> m;
    m.insert(pair<Person,Score>(Person("xm",18),Score(100,90,90)));
    m.insert(pair<Person,Score>(Person("xh",20),Score(100,90,90)));

    m.insert(pair<Person,Score>(Person("aa",30),Score(100,90,90)));
    m.insert(pair<Person,Score>(Person("aa",20),Score(100,90,80)));

    cout<<m.count(Person("xm",18))<<endl;

    map<Person, Score>::iterator iter = m.find(Person("xm",18)); 
    if(iter != m.end())
        iter->second.show();

    for(map<Person,Score>::iterator it = m.begin(); it!=m.end();it++)
    {
        it->first.show();
        it->second.show();
        //cout<<it->second<<endl;
    }
}