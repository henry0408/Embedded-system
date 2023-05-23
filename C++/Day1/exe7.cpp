//string声明以及风格转换

#include <iostream>
#include <cstdio>


using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    string s1 = "hello";
    string s2("world");
    char buf[100];

    //sprintf(buf,"s = %s",s1);   //错误，需要把c++的string转换成c风格
    sprintf(buf,"s = %s",s1.c_str());
    cout<<buf<<endl;

    return 0;
}
