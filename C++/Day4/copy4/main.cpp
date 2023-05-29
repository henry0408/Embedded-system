/*隐式拷贝构造*/

#include <iostream>

using namespace std;

//class Student
//{
//private:
//    string name;
//public:
//    Student(string name)
//    {
//        this->name = name;
//        cout<<"create"<<endl;
//    }

//    void show()
//    {
//        cout<<name<<endl;
//    }
//};

class Student
{
private:
    string name;
public:
//    Student(string name)
//    {
//        this->name = name;
//        cout<<"create"<<endl;
//    }

    void show()
    {
        name = "hangyu";
        cout<<name<<endl;
    }
};

int main()
{
    Student s1;
    s1.show();
    cout<<"-------------"<<endl;

//    Student s2 = s1;
//    s2.show();
//    cout<<"-------------"<<endl;

}
