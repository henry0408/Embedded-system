#include <iostream>

using namespace std;

template <typename T, typename U>


T mul(T a, T b, U c)
{
    cout<<c<<endl;
    return a*b;
}

int main()
{
    // cout<< div<int>(10,2) <<endl;
    // cout<< div<char>('z','x') <<endl;

    mul<int, string>(10,2,"hello");
}