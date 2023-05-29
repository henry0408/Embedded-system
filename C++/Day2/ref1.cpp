/*引用是一个已经存在变量的别名*/

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
    return 0;
}
