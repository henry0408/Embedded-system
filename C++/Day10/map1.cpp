#include <iostream>
#include <map>

using namespace std;

int main()
{
    pair<string,int> p("hehe",18);

    cout<<p.first<<" "<<p.second<<endl;

    //���Զ����ռ�ֵ��������
    map<string,int> m;
    m.insert(p);
    m.insert(pair<string,int>("haha",19));
    m.insert(pair<string,int>("xixi",16));

    //insertʱ���keyֵ��ͬ�����ظ�����
    m.insert(pair<string,int>("xixi",26));

    //���±���ʽ����: ������[keyֵ] = value
    m["kaka"] = 30;
    m["kaka"] = 50;     //ͨ���±긳ֵ�����ݸ���
    m["xixi"] = 50;     //���ݸ���
    //����
    for(map<string,int>::iterator it=m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<"------"<<endl;

    //���keyֵ�����ڣ������ɻ����value=0
    cout<<m["heihei"]<<endl;    //0     

    for(map<string,int>::iterator it=m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    //�ж�key�Ƿ���ֹ������ֹ��򷵻�1�����򷵻�0
    cout<<m.count("heihei")<<endl;

    cout<<"---------"<<endl;

    //�õ��������Ҳ�ɾ��
    map<string,int>::iterator iter = m.find("haha");
    if(iter != m.end())
    {
        m.erase(iter);
    }

    for(map<string,int>::iterator it=m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }


    m.clear();
    m.erase(m.begin(),m.end()); //Ч����ͬ

}