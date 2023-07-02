#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    vector<int> a(30);

    for(int i = 0; i<a.size(); i++)
    {
        a[i] = rand()%100;
    }

    for(int i = 1; i<a.size()+1;i++)
    {
        
        cout<<a[i]<<" ";
        
        if(i%10== 0)
        {
            cout<<" "<<endl;
        }
    }

}