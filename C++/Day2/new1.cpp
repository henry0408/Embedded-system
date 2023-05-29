/*C_++动态申请内存*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *p  = new int();        //不写()则会是随机值（未初始化）
    cout<<*p<<endl;
    cout<<p<<endl;

    int*q = new int(10);        //可以直接赋值
    cout<<*q<<endl;
    cout<<q<<endl;


    int *k = new int[10]();      //数组指针
    for(int i = 0; i<10; i++)
    {
        cout<<k[i]<<endl;
    }
    return 0;
}
