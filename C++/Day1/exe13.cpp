/*
练习6：随机数和字符串数组
随机点名  定义名字数组（字符串数组）string names[]={"rose","jack","tom"}；
			随机抽取一个数组中的人员 

		头文件：#include<cstdlib>
				#include<ctime>
		方法：srand(time(0));初始化随机种子
				rand()%5;生成随机数

*/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    // string names[]={"rose","jack","tom"};
    // srand(time(0));

    // int num = rand()%3;  //5%3 -2 2%2 -2
    // cout<<names[num]<<endl;

    // cout<<sizeof(names)/sizeof(string)<<endl;
    
    
    int length;
    cout<<"please enter the len"<<endl;
    cin>>length;
    string str[length];
    for(int i = 0; i<length; i++)
    {
        /* code */
        string s1;
        cout<<"please enter the name"<<endl;
        cin>>s1;
        str[i] = s1;
    }

    for(int j = 0; j<length; j++)
    {
        cout<<str[j]<<endl;
    }
    

    return 0;
}
