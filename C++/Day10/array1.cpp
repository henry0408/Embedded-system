#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,5> a = {1,2,3,4,5};
    for(auto it = a.begin(); it!=a.end();it++)
    {
        cout<<*it<<endl;
    }

    cout<<"-----"<<endl;
    for(auto it = a.rbegin(); it!=a.rend();it++)
    {
        cout<<*it<<endl;
    }
}