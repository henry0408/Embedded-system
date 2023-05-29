/*引用交换两个数字*/

#include <iostream>

using namespace std;

void swap(int&a, int&b)
{
    int swap = a;
    a = b;
    b = swap;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10;
    int b = 20;

    int &x = a;
    int &y = b;
    swap(x,y);

    cout<<a<<endl;
    cout<<b<<endl;

    return 0;
}
