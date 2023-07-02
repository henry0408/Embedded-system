#include <iostream>

using namespace std;

template <typename T>

// int div(T a, T b)
// {
//     return a/b;
// }

T mul(T a, T b)
{
    return a*b;
}

int main()
{
    // cout<< div<int>(10,2) <<endl;
    // cout<< div<char>('z','x') <<endl;

    cout<<mul<int>(10,2)<<endl;
}