#include <iostream>

using namespace std;

void fun(signed char ch)
{
    if(ch== 200)
    {
        cout<<true<<endl;
    }
    else
    {
        cout<<ch<<endl;
        cout<<false<<endl;
        
    }
}

int main()
{
    signed char ch = 200;
    fun(ch);
}