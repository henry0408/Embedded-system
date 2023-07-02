#include <iostream>

using namespace std;

template<typename T>

void show(T a)
{
    cout<<a<<endl;
}


void show(int a)
{
    cout<<a<<endl;
}


int main()
{
    show(12);
}