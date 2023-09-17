#include <iostream>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout<<"Animal gouzao"<<endl;
	}
	virtual void speak() = 0;
	
	~Animal()
	{
		cout<<"Animal xigou"<<endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
	{
		cout<<"Cat gouzao"<<endl;
		m_Name = new string(name);
	}
	
	void speak()
	{
		cout<< *m_Name <<" cat is speaking"<<endl;
	}
	
	~Cat()
	{
		if(m_Name != NULL)
		{
			cout<<"Cat xigou"<<endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	
	string* m_Name;
};

int main()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
}