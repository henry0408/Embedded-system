/*���ú���(���ô���)*/

#include <iostream>

using namespace std;

int& fun1(int &p)
{
    p = 100;
    return p;
}

int main(int argc, char const *argv[])
{
    
    // int &p  =1;     //�ó�����ʼ��������

    int a = 10;
    int &p =a;
    cout<<a<<endl;
    cout<<p<<endl;
    fun1(p) = 88;             //��fun(a)Ч����ͬ
    cout<<a<<endl;
    cout<<p<<endl;
}