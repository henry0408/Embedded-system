/*引用和指针的区别：
指针指向空
引用必须先初始化
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int *a;
    int &b;     //报错
    return 0;
}