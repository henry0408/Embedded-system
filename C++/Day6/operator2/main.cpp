/*设计一个三角形类Triangle 包含三角形三条边长的私有数据成员
 另有一个重载运算符'+'  以实现求两个三角形周长之和
    注意：两个三角形对象相加
    */

#include <iostream>

using namespace std;

class Triangle
{
    int a, b, c;
public:
    void show()
    {
        cout<<a+b+c<<endl;
    }


    int operator +(const Triangle&)
    {
        return this->a+
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

