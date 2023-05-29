#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int*p = new int(10);
    for(int i = 0; i<10; i++)
    {
        p[i] = i;
    }
    for(int i = 0; i<10; i++)
    {
        cout<<p[i]<<endl;
    }

    delete [] p;        //ÊÍ·Å

    for(int i = 0; i<10; i++)
    {
        cout<<p[i]<<endl;
    }

    return 0;
}
