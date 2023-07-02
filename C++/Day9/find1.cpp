#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;

    //查找vector中为3的数值的下标
    vector<int>::iterator it = find(a.begin(),a.end(),3);

    //找到返回元素所在位置，没找到返回最后一个元素的下一个位置
    if(it != a.end())
    {
        a.erase(it);
    }

}