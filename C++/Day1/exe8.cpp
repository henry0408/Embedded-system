//string�����Լ����ת��

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string s1 = "hello";
    string s2("world");
    string s3 = s1+s2;

    cout<<s3<<endl;

    s3+=2;        //stringֻ��ƴ��string����c����ַ���
    cout<<s3<<endl;
    return 0;
}
