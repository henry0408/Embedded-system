//string�����Լ����ת��

#include <iostream>
#include <cstdio>


using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    string s1 = "hello";
    string s2("world");
    char buf[100];

    //sprintf(buf,"s = %s",s1);   //������Ҫ��c++��stringת����c���
    sprintf(buf,"s = %s",s1.c_str());
    cout<<buf<<endl;

    return 0;
}
