#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}
	
	Person& PersonAddAge(Person p)	//要返回本体，所以用引用类型
	{
		this->age += p.age;
		return *this;		//返回一个类
	}
	
	int age;
};

void test()
{
	Person p1(10);
	Person p2(10);
    
	p2.PersonAddAge(p1).PersonAddAge(p1);	//链式编程
	cout<<"age of p2: "<<p2.age<<endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
