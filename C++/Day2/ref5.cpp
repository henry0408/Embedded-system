/*引用函数(引用传递)*/

#include <iostream>

using namespace std;

void fun(int &p)
{
    p = 100;
}

int main(int argc, char const *argv[])
{
    
    // int &p  =1;     //用常量初始化，报错

    int a = 10;
    int &p =a;
    cout<<a<<endl;
    cout<<p<<endl;
    fun(p);             //和fun(a)效果相同
    cout<<a<<endl;
    cout<<p<<endl;
}