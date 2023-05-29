#include <iostream>

using namespace std;

class Array
{
public:
    int arr[3][3];
    void init()
    {
        for(int i = 0,m=0; i<3; i++)
        {
            //cout<<m<<endl;
            for(int j = 0; j<3; j++)
            {
                arr[i][j] = j+m;
            }
            m++;
        }
    }

    void print(char ch)
    {
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                cout<<arr[i][j]<<"#";
            }
            cout<<""<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Array arr;
    arr.init();
    arr.print('#');
    return 0;
}
