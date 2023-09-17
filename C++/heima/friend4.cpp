/*全局函数做友元练习*/
#include <iostream>
using namespace std;

class Building
{
    friend void visit(Building& building);
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

void visit(Building& building) 
{
    cout<<"sitting room: "<<building.m_sittingRoom<<endl;
    cout<<"living room: "<<building.m_livingRoom<<endl;
}

int main()
{
    Building b;
    visit(b);
}