//string�ж��Ƿ�Ϊ�գ��Լ���string����

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string s1 = "hello";
    string s2("world is");
    if(s1.empty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }

    //��һ��stringȡsizeof()�Ľ����һ���ģ�������32
    cout<<sizeof(s2)<<endl;
    cout<<sizeof(s1)<<endl;

    cout<<sizeof(string)<<endl;

    cout<<s2.size()<<endl;


    return 0;
}
