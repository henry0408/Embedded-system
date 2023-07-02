#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i<10; i++)
    {
        v.push_back(i);
    }

    //容器适配器创建
    stack<int,vector<int>> s(v);       // >>不能连着写

    for(int i = 10; i<20; i++)
        s.push(i);
    
    //不为空则出栈
    while(!s.empty())
    {
        //获取栈顶元素
        cout<<s.top()<<endl;
        s.pop();
    }
}