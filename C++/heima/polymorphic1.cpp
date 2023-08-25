#include <iostream>

using namespace std;

class virtualCalculator
{
public:
    int num1;
    int num2;

    virtual int operation ()
    {
        return 0;
    }
};

class SumCalculator : public virtualCalculator
{
public:
    int operation ()
    {
        return num1+num2;
    }
};

class SubCalculator : public virtualCalculator
{
public:
    int operation ()
    {
        return num1-num2;
    }
};

int main()
{
    virtualCalculator *vc = new SumCalculator;
    vc->num1 = 10;
    vc->num2 = 10;

    cout<< vc->num1 <<" + "<<vc->num2<< " = " << vc->operation() <<endl;
    delete vc;

    vc = new SubCalculator;
    vc->num1 = 10;
    vc->num2 = 10;

    cout<< vc->num1 <<" - "<<vc->num2<< " = " << vc->operation() <<endl;
    delete vc;
}

