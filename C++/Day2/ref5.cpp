/*���ú���(���ô���)*/

#include <iostream>

using namespace std;

void fun(int &p)
{
    p = 100;
}

int main(int argc, char const *argv[])
{
    
    // int &p  =1;     //�ó�����ʼ��������

    int a = 10;
    int &p =a;
    cout<<a<<endl;
    cout<<p<<endl;
    fun(p);             //��fun(a)Ч����ͬ
    cout<<a<<endl;
    cout<<p<<endl;
}