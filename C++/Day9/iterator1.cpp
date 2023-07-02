#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    for(int i = 0; i<100; i++)
    {
        a.push_back(i);
    }

    for(vector<int>::iterator i = a.begin(); i!= a.end(); i++)
    {
        cout<<*i<<endl;
    }
        
    
}