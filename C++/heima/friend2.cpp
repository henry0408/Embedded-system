#include <iostream>

using namespace std;

class Building;

class myFriend
{
public:
	myFriend();
	Building * building;
	void visit();	//参观函数，访问Building中的属性
};


class Building
{	
	friend class myFriend;
public:
	Building();
	string m_SittingRoom;
	
private:
	string m_BedRoom;
};

//类外实现成员构造
Building::Building()
{
	m_SittingRoom = "sr";
	m_BedRoom = "br";
}

myFriend::myFriend()
{
	//创建building类对象
	building = new Building;
}

void myFriend::visit()
{
	cout<<"visiting "<<building->m_SittingRoom<<endl;
	cout<<"visiting "<<building->m_BedRoom<<endl;
}

void test()
{
	myFriend f;
	f.visit();
}

int main()
{
    test();
}