/*namespace��ʶ����ͻ*/

#include <iostream>

using namespace std;

namespace MyStd
{
    int age = 18;
    char name[] = "hangyu";
}

using namespace MyStd;

int age = 20;

int main(int argc, char const *argv[])
{
    /* code */
    cout<< ::age<<endl;         //ȫ�ֱ���
    cout<< MyStd::age<<endl;
    //cout<< age<<endl;         //����ambiguous
    return 0;
}
