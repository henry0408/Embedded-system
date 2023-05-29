/*namespace±êÊ¶·û³åÍ»*/

#include <iostream>

using namespace std;

namespace MyStd
{
    int age = 18;
}

namespace YourStd
{
    int age = 19;
} // namespace YourStd

using namespace MyStd;
using namespace YourStd;

int main(int argc, char const *argv[])
{
    /* code */
    
    cout<< YourStd::age<<endl;
    //cout<< age<<endl;     //±¨´í
    return 0;
}
