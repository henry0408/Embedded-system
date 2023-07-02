#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l;
    l.insert(l.begin(),18);
    l.insert(l.begin(),28);
    l.push_back(30);

    l.insert(l.begin(),2,88);
    for(list<int>::iterator it = l.begin();it!= l.end();it++)
    {
        cout<<*it<<endl;
    }

    cout<<"---------"<<endl;

    l.sort();
    for(list<int>::iterator it = l.begin();it!= l.end();it++)
    {
        cout<<*it<<endl;
    }
}