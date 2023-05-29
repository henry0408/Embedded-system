/*引用函数(引用传递)*/

#include <iostream>

using namespace std;

int& fun1(int &p)
{
    p = 100;
    return p;
}

int main(int argc, char const *argv[])
{
    
    // int &p  =1;     //用常量初始化，报错

    int a = 10;
    int &p =a;
    cout<<a<<endl;
    cout<<p<<endl;
    fun1(p) = 88;             //和fun(a)效果相同
    cout<<a<<endl;
    cout<<p<<endl;
}