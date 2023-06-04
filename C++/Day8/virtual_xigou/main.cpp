#include <iostream>

using namespace std;

class Baby
{
public:
    Baby()
    {
        cout<<"baby create"<<endl;
    }

//    //虚析构
//    virtual ~Baby()
//    {
//        cout<<"baby delete"<<endl;
//    }

    //纯虚析构，需要类外实现
    virtual ~Baby() = 0;
};

Baby::~Baby()
{
    cout<<"baby delete"<<endl;
}

class Student : public Baby
{
public:
    Student()
    {
        cout<<"Student create"<<endl;
    }
    ~Student()
    {
        cout<<"Student delete"<<endl;
    }
};

int main()
{
    Baby *b = new Student;
    delete b;
    return 0;
}

