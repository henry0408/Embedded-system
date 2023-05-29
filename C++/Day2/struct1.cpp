#include <iostream>

using namespace std;

struct Book
{
    int price;
    string name;
    void show()
    {
        cout<<name<<" "<<price<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Book b = {12,"asdasd"};     //写不写struct都可以

    b.show();
    
    return 0;
}
