
/*��������
������������ͬ������������/���ͣ���ͬ���뷵��ֵ�޹�
*/

#include <iostream>

using namespace std;

void print(int a)
{
    cout<<a<<endl;
}

void print(int a, int b)
{
    cout<<a<<endl;
    cout<<b<<endl;
}

void print(char a)
{
    cout<<a<<endl;
}

// int print(int a)     //����
// {
//     cout<<a<<endl;
//     return 0;
// }

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10, b = 5;
    print(a);
    print(a,b);
    char ch = 'a';
    print(ch);
    return 0;
}
