/*成员函数做友元*/
#include <iostream>

using namespace std;

class Building;
class Friend
{
public:
    Friend();
    Building* b;
    void visit();
};

class Building
{
    friend void Friend::visit();
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

Friend::Friend()
{
    b = new Building;
}

void Friend::visit()
{
    cout<<b->m_livingRoom<<endl;
    cout<<b->m_sittingRoom<<endl;
}

int main()
{
    Friend f;
    f.visit();
}
