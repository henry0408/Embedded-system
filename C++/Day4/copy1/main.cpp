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

int main()
{
    Student s1("xm");
    cout<<"-------------"<<endl;

    Student s2 = s1;
    s2.show();
    cout<<"-------------"<<endl;

    Student s3(s1);
    s3.show();
    cout<<"-------------"<<endl;

    Student *s5 = new Student("tom");
    s5->show();
    cout<<"-------------"<<endl;

    Student *s4 = new Student(*s5);		//堆空间
    s4->show();
    cout<<"-------------"<<endl;

    Student *s6 = new Student(s1);		//栈空间
    s6->show();
    cout<<"-------------"<<endl;

    Student *s7 = s5;
    s7->show();			//不拷贝
    cout<<"-------------"<<endl;
}
