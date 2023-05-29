#include <iostream>

using namespace std;

class Student;
void print(Student *p);

class Student
{
private:
    int age;
public:
    Student(int age):age(age)
    {

    }

    void show()
    {
        cout<<age<<endl;
    }

    void doSomething()
    {
        print(this);
    }
};

void print(Student *p)
{
    p->show();
}

int main()
{
    cout << "Hello World!" << endl;
    Student p(18);
    p.show();
    p.doSomething();
    return 0;
}

