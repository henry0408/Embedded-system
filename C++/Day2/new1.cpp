/*C_++��̬�����ڴ�*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *p  = new int();        //��д()��������ֵ��δ��ʼ����
    cout<<*p<<endl;
    cout<<p<<endl;

    int*q = new int(10);        //����ֱ�Ӹ�ֵ
    cout<<*q<<endl;
    cout<<q<<endl;


    int *k = new int[10]();      //����ָ��
    for(int i = 0; i<10; i++)
    {
        cout<<k[i]<<endl;
    }
    return 0;
}
