/*Àà×öÓÑÔªÁ·Ï°*/
#include <iostream>
using namespace std;

class Friend;
class Building
{
    friend Friend;
public:
    Building()
    {
        m_livingRoom = "lr";
        m_sittingRoom = "sr";
    }
    string m_sittingRoom;
private:   
    string m_livingRoom;
};

class Friend
{
public:
    Friend();
    Building* building;
    void visit();
};

void Friend::visit()
{
    cout<<building->m_sittingRoom<<endl;
    cout<<building->m_livingRoom<<endl;
}

Friend::Friend()
{
    building = new Building;
}


int main()
{
    Friend f;
    f.visit();
}
