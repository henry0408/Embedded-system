/*引用不能改变指向，但值可以变*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10;
    int &b = a;
    cout<<a<<endl;
    cout<<b<<endl;

    cout<<&a<<endl;
    cout<<&b<<endl;

    int c = 20;
    b =c;
    cout<<b<<endl;  //20
    cout<<&b<<endl; //没变

    cout<<a<<endl;      //20
    cout<<&a<<endl;     //没变


    return 0;
}
