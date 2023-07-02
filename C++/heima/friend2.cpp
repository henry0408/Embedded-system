#include <iostream>

using namespace std;

class Building;

class myFriend
{
public:
	myFriend();
	Building * building;
	void visit();	//�ιۺ���������Building�е�����
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

//����ʵ�ֳ�Ա����
Building::Building()
{
	m_SittingRoom = "sr";
	m_BedRoom = "br";
}

myFriend::myFriend()
{
	//����building�����
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