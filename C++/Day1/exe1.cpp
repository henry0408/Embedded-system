/*输入输出*/

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    for(int i = 0; i<5; i++)
    {
        cout <<i<<" ";
    }

    //输入
    int age;
    cin>>age;
    cout<<age<<endl;

    //多个输入
    char mychar;
    cin>>age>>mychar;
    cout<< age <<" "<< mychar <<endl;

    //多个输出
    char ch = 'a';
    cout<< age <<" "<< ch <<endl;

    return 0;
}
