
#include<iostream>
using namespace std;

int main()
{
	int a=100;
	int &ref = a ;//1.���ñ����ʼ��
    cout<<ref<<endl;//100

    int b=78;
	ref = b;    //2.���ò����Ըı䷽��ʹ��b������a��ֵ
    cout<<ref<<endl;//78

    cout<<a<<endl;//78

    int c;
    c = ref;
    cout<<c<<endl;
    cout<<a<<endl;//78
}