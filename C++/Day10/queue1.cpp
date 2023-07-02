#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Person
{
    int age;
public:
    Person(int age):age(age){}
    void show() const
    {
        cout<<age<<endl;
    }
    bool operator <(const Person& o) const
    {
        if(this->age < o.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    priority_queue<Person,vector<Person> >p;
    p.push(Person(12));
    p.push(Person(1));
    p.push(Person(6));

    while(!p.empty())
    {
        p.top().show();
        p.pop();
    }
}