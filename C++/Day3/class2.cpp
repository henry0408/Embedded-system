/*¶Ñ¿Õ¼ä´´½¨class*/

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
    Student *s = new Student;
    s->init("xm",20);
    s->print_info();
    delete s;
    s = NULL;
    return 0;
}
