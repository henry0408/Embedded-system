#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(30);
    s.insert(30);
    //���Զ���������

    //����������
    for(set<int>::iterator it = s.begin();it!= s.end();it++)
    {
        cout<<*it<<endl;    
    }

    //���
    //s.clear();

    //��С
    cout<<s.size()<<endl;

    //����
    cout<<s.count(30)<<endl;

    //����2
    set<int>::iterator iter = s.find(30);
    //ɾ��
    if(iter != s.end())
    {
        s.erase(iter);
    }
    //ɾ��2
    s.erase(10);    //�ùؼ���ɾ��

    //ɾ��3
    s.erase(s.begin(),s.end()); //����ɾ��
}