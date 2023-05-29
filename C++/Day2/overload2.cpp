/*函数重载
条件：名字相同，参数（个数/类型）不同，与返回值无关
*/

#include <iostream>

using namespace std;

int dev(int a, int b)
{
    return a/b;
}

float dev(float a, float b)
{
    return a/b;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10, b = 3;
    float x = 10, y = 3;
    cout<<dev(x,y)<<endl;
    cout<<dev(a,b)<<endl;
    return 0;
}