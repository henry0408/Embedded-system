/*Person类，包含私有属性：姓名name，性别bool gender，年龄age，另一个对象的指针 Person *lover;
        1.构造函数初始化成员变量 name gender
        2.成员函数setAge给年龄赋值
        3.成员函数marry(Person& other)    输出name"和"other.name"喜结良缘!";
        4.成员函数show(); 输出"大家好！我是"gender，name，今年"age;
                          输出"爱人是:"lover->name;
private:
        string name;
        bool gender;
        int age;
        Person *lover;手指头
 *
 */

#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    bool gender;
    int age;
    Person *lover;
public:
    Person(string name, bool gender)
    {
        this->name = name;
        this->gender = gender;
    }

    void set_age(int age)
    {
        this->age = age;
    }

    void marry(Person *lover)
    {
        this->lover = lover;
        cout<<this->name<<" "<<lover->name<<" get married"<<endl;
    }

    void show()
    {
        cout<<"Hi, I am "<<this->name<<" age is: "<<this->age<<" my lover is: "<<this->lover->name<<endl;
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Person p1("Jack", 1);
    Person p2("Alice",0);
    p1.marry(&p2);

    p1.set_age(20);
    p1.show();
    return 0;
}

