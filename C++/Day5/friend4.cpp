#include <iostream>

using namespace std;

class Friend
{
    friend void setAge(Friend& f);
private:
    int age;
public:
    void setAge(int age){this->age = age;}
    void getAge()
    {
        cout<<age<<endl;
    }
};

void setAge(Friend& f)
{
    f.age = 20;
}

int main()
{
    Friend f;
    f.setAge(18);
    f.getAge();

    setAge(f);
    f.getAge();
}