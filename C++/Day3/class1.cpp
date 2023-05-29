#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    int age;

    void init(string str, int Myage)
    {
        name = str;
        age = Myage;
    }

    void set_name(string str)
    {
        name = str;
    }
    void print_info()
    {
        cout<<name<<" "<<age<<endl;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Student s;
    s.name = "hangyu";
    s.age = 20;
    //初始化不能用大括号形式

    s.set_name("xm");
    s.print_info();

    return 0;
}
