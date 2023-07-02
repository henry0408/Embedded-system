#include <iostream>

using namespace std;

class Building
{
	friend void visit(Building* building);
	
public:
	Building()
	{
		m_SittingRoom = "sr";
		m_BedRoom = "br";
	}
	
	string m_SittingRoom;
	
private:
	string m_BedRoom;
};

void visit(Building* building)
{
	cout<<"Visit sitting room "<< building->m_SittingRoom <<endl;
	cout<<"Visit bedroom "<< building->m_BedRoom <<endl;
}

int main()
{
	Building b;
	visit(&b);
}