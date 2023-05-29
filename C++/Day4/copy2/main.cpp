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


void fun(Student s)
{
    s.show();
}

void fun1(Student& s)
{
    s.show();
}

int main()
{
    Student s1("xm");
    cout<<"-----------------"<<endl;

    fun(s1);
    cout<<"-----------------"<<endl;

    fun1(s1);
    cout<<"-----------------"<<endl;

    fun(Student("xh"));

}
