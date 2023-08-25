#include <iostream>

using namespace std;

class Animal
{
public:
	void speak()
	{
		cout<<"animal is speaking"<<endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout<<"cat is speaking"<<endl;
	}
};

void doSpeak(Animal &animal)
{
	animal.speak();
}

void test()
{
	Cat cat;
	doSpeak(cat);
}

int main()
{
	test();
}