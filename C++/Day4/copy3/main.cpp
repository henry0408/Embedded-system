#include <iostream>

using namespace std;

class Student
{
private:
    string name;
public:
    Student(string name)
    {
        this->name = name;
        cout<<"create"<<endl;
    }
    Student(const Student& other)		//拷贝构造
    {
        this->name = other.name;
        cout<<"copy"<<endl;
    }
    void show()
    {
        cout<<name<<endl;
    }
};


Student fun()
{
    Student s("xq");
    return s;
}

Student fun1()
{
    Student *s = new Student("xl");

    return *s;
}

int main()
{
    fun();
    cout<<"--------------"<<endl;
    fun1();
}
