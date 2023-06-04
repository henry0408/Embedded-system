/*只有虚函数，父类(基类)指针才能用子类的函数*/

#include <iostream>

using namespace std;

class Person
{
    int age;
public:
    virtual void show()
    {
        
    }
};

