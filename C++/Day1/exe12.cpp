//cin让用户输入字符串（遇到空格就会停）

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string s1;

    cin>>s1;
    for(int i = 0; i<s1.size();i++)
    {
        if(s1[i]>='A' && s1[i]<='Z')
            s1[i]+=32;
        else if(s1[i]>='a' && s1[i]<='z')
            s1[i]-=32;
    }

    cout<<s1<<endl;

    return 0;
}

/*
输入：hangyu CHEN
输出：HANGYU



*/