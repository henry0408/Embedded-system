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

    //��������������
    stack<int,vector<int>> s(v);       // >>��������д

    for(int i = 10; i<20; i++)
        s.push(i);
    
    //��Ϊ�����ջ
    while(!s.empty())
    {
        //��ȡջ��Ԫ��
        cout<<s.top()<<endl;
        s.pop();
    }
}