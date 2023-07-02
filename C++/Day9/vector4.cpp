#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> a(11);
    for(int i = 0; i<=10; i++)
    {
        a[i] = i;
    }
    a.push_back(10);

    for(int i = 0; i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    

    for(vector<int>::iterator i = a.begin(); i!= a.end();)
    {
        cout<<"determine "<<*i<<endl;
        if(*i%2 == 0)
        {
            i = a.erase(i);
            cout<<"i is: "<<*i<<endl;
        }
        else
        {
            i++;
        }
    }

    for(int i = 0; i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }

}