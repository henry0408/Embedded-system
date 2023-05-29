/*常引用*/


#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    const int&p = 10;       //可以用常量初始化
    
    int e = 10;
    const int&q = 10+e;     //可以用临时变量初始化

    cout<<q<<endl;
    return 0;
}

