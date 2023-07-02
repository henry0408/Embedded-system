#include <iostream>
#include <map>

using namespace std;

int main()
{
    pair<string,int> p("hehe",18);

    cout<<p.first<<" "<<p.second<<endl;

    //会自动按照键值升序排序
    map<string,int> m;
    m.insert(p);
    m.insert(pair<string,int>("haha",19));
    m.insert(pair<string,int>("xixi",16));

    //insert时如果key值相同，不重复插入
    m.insert(pair<string,int>("xixi",26));

    //以下标形式插入: 容器名[key值] = value
    m["kaka"] = 30;
    m["kaka"] = 50;     //通过下标赋值，数据覆盖
    m["xixi"] = 50;     //数据覆盖
    //遍历
    for(map<string,int>::iterator it=m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<"------"<<endl;

    //如果key值不存在，则依旧会插入value=0
    cout<<m["heihei"]<<endl;    //0     

    for(map<string,int>::iterator it=m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    //判断key是否出现过，出现过则返回1，否则返回0
    cout<<m.count("heihei")<<endl;

    cout<<"---------"<<endl;

    //用迭代器查找并删除
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
    m.erase(m.begin(),m.end()); //效果相同

}