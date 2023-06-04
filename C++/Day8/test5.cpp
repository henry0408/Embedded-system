
#include <iostream>
using namespace std;

//����People
class People{
public:
    People(string name, int age): m_name(name), m_age(age){}
    virtual void display(){
        cout<<m_name<<"����"<<m_age<<"���ˣ��Ǹ���ҵ����"<<endl;
    }
protected:
    string m_name;
    int m_age;
};
//������Teacher
class Teacher: public People{
public:
    Teacher(string name, int age, int salary): People(name, age), m_salary(salary){}
    void display(){
        cout<<m_name<<"����"<<m_age<<"���ˣ���һ����ʦ��ÿ����"<<m_salary<<"Ԫ�����롣"<<endl;
    }
private:
    int m_salary;
};
int main(){
    People *p = new People("����", 23);
    p -> display();

    p = new Teacher("����", 45, 8200);
    p -> display();

    return 0;
}