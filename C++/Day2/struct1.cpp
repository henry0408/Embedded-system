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
    Book b = {12,"asdasd"};     //д��дstruct������

    b.show();
    
    return 0;
}
