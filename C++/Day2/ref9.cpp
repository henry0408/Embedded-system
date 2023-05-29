
#include<iostream>
using namespace std;

int main()
{
	int a=100;
	int &ref = a ;//1.引用必须初始化
    cout<<ref<<endl;//100

    int b=78;
	ref = b;    //2.引用不可以改变方向，使用b给变量a赋值
    cout<<ref<<endl;//78

    cout<<a<<endl;//78

    int c;
    c = ref;
    cout<<c<<endl;
    cout<<a<<endl;//78
}