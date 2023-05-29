/*namespace标识符冲突*/

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
    cout<< ::age<<endl;         //全局变量
    cout<< MyStd::age<<endl;
    //cout<< age<<endl;         //报错，ambiguous
    return 0;
}
