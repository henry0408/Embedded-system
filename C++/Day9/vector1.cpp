#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;  //�����������յģ�

    vector<int>a1(10);  //����Ϊ10 

    vector<int> a2(10,30);
    //������С��10��ÿһ��Ԫ�ص�ֵ����30

    for(int i = 0; i<a2.size(); i++)
    {
        cout<<a2[i]<<endl;
    }

    vector<int> a3 = {1,2,3};
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    a3.insert(a3.begin(),10);
    //�ڵ�һ��λ�ò���10
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //����ƫ��
    a3.insert(a3.begin()+2,10);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //����������λ�ã����뼸�����������ֵ
    a3.insert(a3.begin(),5,20);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //β��
    a3.push_back(90);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }

    //β�巽��2
    a3.insert(a3.end(),120);
    for(int i = 0; i<a3.size(); i++)
    {
        cout<<a3[i]<<endl;
    }
}