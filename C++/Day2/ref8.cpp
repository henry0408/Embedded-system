/*������*/


#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    const int&p = 10;       //�����ó�����ʼ��
    
    int e = 10;
    const int&q = 10+e;     //��������ʱ������ʼ��

    cout<<q<<endl;
    return 0;
}

