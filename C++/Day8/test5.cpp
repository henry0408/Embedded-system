
#include <iostream>
using namespace std;

//基类People
class People{
public:
    People(string name, int age): m_name(name), m_age(age){}
    virtual void display(){
        cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
    }
protected:
    string m_name;
    int m_age;
};
//派生类Teacher
class Teacher: public People{
public:
    Teacher(string name, int age, int salary): People(name, age), m_salary(salary){}
    void display(){
        cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
    }
private:
    int m_salary;
};
int main(){
    People *p = new People("啊啊", 23);
    p -> display();

    p = new Teacher("嘻嘻", 45, 8200);
    p -> display();

    return 0;
}