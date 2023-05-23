//string声明以及风格转换

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

    s3+=2;        //string只能拼接string或者c风格字符串
    cout<<s3<<endl;
    return 0;
}
