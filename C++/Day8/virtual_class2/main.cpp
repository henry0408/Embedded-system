/*
 *
 *
 * 1.设计一个虚基类Base         包括：protected数据: 姓名和年龄       成员函数eat();
2.由Base类派生出领导类Leader 包含:protected数据：职务duty和部门department  成员函数lead();
3.再有Base类派生出工程师类Engineer
                    包含：私有数据职称major 专业professional  成员函数develop();
4.然后由Leader类和Engineer类派生出主任工程师类Boss
5. main里创建Boss

*/


#include <iostream>

using namespace std;

class Base
{
protected:
    string name;
    int age;
public:
    Base(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void eat()
    {
        cout<<"eat"<<endl;
    }
};

class Leader : virtual public Base
{
protected:
    string duty;
    string department;
public:
    Leader(string name, int age,string duty,string department):Base(name,age),duty(duty),department(department){}

    void lead()
    {
        cout<<"lead"<<endl;
    }
};

class Engineer: virtual public Base
{
private:
    string major;
    string professional;

public:
    Engineer(string name, int age,string major, string professional):Base(name,age),major(major),professional(professional){}

    void develop()
    {
        cout<<"develop"<<endl;
    }
};

class Boss: public Leader, public Engineer
{
public:

    Boss(string name, int age, string duty, string department, string major, string professional):
        Base(name,age),Leader(name,age,duty,department),Engineer(name,age,major, professional)
    {
    }

};

int main()
{

    Boss b("hah",18,"AI","Engineering","Test","ELEC");
    b.develop();
    b.eat();
    return 0;
}

