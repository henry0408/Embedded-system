#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;  //定义容器（空的）

    vector<int>a1(10);  //容量为10 

    vector<int> a2(10,30);
    //容器大小是10，每一个元素的值都是30

    for(int i = 0; i<a2.size(); i++)
    {
        cout<<a2[i]<<endl;
    }

    vector<int> a3 = {1,2,3};
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    a3.insert(a3.begin(),10);
    //在第一个位置插入10
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //插入偏移
    a3.insert(a3.begin()+2,10);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //参数：插入位置，插入几个，插入的数值
    a3.insert(a3.begin(),5,20);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //尾插
    a3.push_back(90);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //尾插方法2
    a3.insert(a3.end(),120);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }
}