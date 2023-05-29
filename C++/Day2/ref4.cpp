/*
普通引用不能用常量或者临时值初始化
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    // int &p  =1;     //用常量初始化，报错

    int a = 10;
    int &p =a+1;       //用临时值初始化，报错
}