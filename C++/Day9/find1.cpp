#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;

    //����vector��Ϊ3����ֵ���±�
    vector<int>::iterator it = find(a.begin(),a.end(),3);

    //�ҵ�����Ԫ������λ�ã�û�ҵ��������һ��Ԫ�ص���һ��λ��
    if(it != a.end())
    {
        a.erase(it);
    }

}