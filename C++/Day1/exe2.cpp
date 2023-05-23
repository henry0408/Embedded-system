//��дתСд

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    char ch;
    cin>>ch;
    if(ch>='a')
        ch-=32;
    else
        ch+=32;

    cout<<ch;
    return 0;
}
