#include <iostream>

using namespace std;

class AbstractDrinking
{
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void Pour() = 0;
	virtual void Add() = 0;
	
	void make()
	{
		Boil();
		Brew();
		Pour();
		Add();
	}
};

class Coffee: public AbstractDrinking
{
public:
	void Boil()
	{
		cout<<"boiling pure water"<<endl;
	}
	void Brew()
	{
		cout<<"brew coffee"<<endl;
	}
	void Pour()
	{
		cout<<"Pour into coffee cup"<<endl;
	}
	void Add()
	{
		cout<<"Add sugar and milk"<<endl;
	}
};

class Tea: public AbstractDrinking
{
public:
	void Boil()
	{
		cout<<"boiling pure water"<<endl;
	}
	void Brew()
	{
		cout<<"brew tea"<<endl;
	}
	void Pour()
	{
		cout<<"Pour into tea cup"<<endl;
	}
	void Add()
	{
		cout<<"Add lemon"<<endl;
	}
};

void doWork(AbstractDrinking* abs)
{
	abs->make();
}

int main()
{
	doWork(new Coffee);
}