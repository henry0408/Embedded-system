#include <iostream>
#include <vector>

using namespace std;


void fun(vector<int>& v)
{
    v[8] = 999;
}

int main()
{
    vector<int> a(10);
    for(int i = 0; i<10; i++)
    {
        a[i] = i;
    }
    //fun(a);

    for(vector<int>::iterator i = a.begin(); i!= a.end();i++)
    {
        cout<<*i<<endl;
    }

    cout<<"-----"<<endl;

    a.erase(a.begin()+3,a.begin()+7);
    for(vector<int>::iterator i = a.begin(); i!= a.end();i++)
    {
        cout<<*i<<endl;
    }
}