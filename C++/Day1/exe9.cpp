//string比较大小

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string s1 = "hello";
    string s2("world");
    if(s1>s2)
    {
        cout<<"larger"<<endl;
    }
    else
    {
        cout<<"smaller"<<endl;
    }
    return 0;
}
