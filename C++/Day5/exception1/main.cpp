#include <iostream>

using namespace std;

class ExceptA
{
public:
    void show()
    {
        cout<<"exception A"<<endl;
    }
};

class ExceptB
{
public:
    void show()
    {
        cout<<"exception B"<<endl;
    }
};

int div(int a, int b)
{
    if(b == 0)
    {
        //throw b;        //抛出基本类型异常
        ExceptA a;
        throw a;           //抛出自定义异常
    }
    return a/b;
}

double div(double a, double b)
{
    if(b == 0)
    {
        //throw b;        //抛出基本类型异常
        ExceptB b;
        throw b;           //抛出自定义异常
    }
    return a/b;
}

int main()
{
    try
    {
        div(10,0);
        div(10.0,0.0);
    }
    catch(ExceptA e)
    {
        e.show();
    }

    catch(ExceptB e)
    {
        e.show();
    }


    return 0;
}

