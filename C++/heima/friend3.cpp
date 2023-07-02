#include <iostream>

using namespace std;

class Building;

class myFriend
{
public:
	myFriend();

	Building *building;
	
	void visit();
	void visit2();
};

class Building
{
	friend void myFriend::visit();	//告诉Building, myFriend下的visit成员函数为友元，可以访问私有内容。

public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};


Building::Building()
{
	m_SittingRoom = "sr";
	m_BedRoom = "br";
}

myFriend::myFriend()
{
	building = new Building;
}

void myFriend::visit()
{
	cout<<"visiting "<<building->m_SittingRoom<<endl;
	cout<<"visiting "<<building->m_BedRoom<<endl;
}

void myFriend::visit2()
{
	cout<<"visiting "<<building->m_SittingRoom<<endl;
	//cout<<"visiting "<<building->m_BedRoom<<endl;
}

void test()
{
	myFriend f;
	f.visit();
	f.visit2();
}

int main()
{
	test();
}