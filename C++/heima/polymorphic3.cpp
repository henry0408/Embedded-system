#include <iostream>

using namespace std;

class virtualDrink
{
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pour() = 0;
    void make()
    {
        boil();
        brew();
        pour();
    }
};

class Coffee : public virtualDrink
{
public:
    void boil()
    {
        cout<<"boil water 1"<<endl;
    }
    void brew()
    {
        cout<<"brew coffee"<<endl;
    }
    void pour()
    {
        cout<<"pour into coffee cup"<<endl;
    }

};

class Tea : public virtualDrink
{
public:
    void boil()
    {
        cout<<"boil water 2"<<endl;
    }
    void brew()
    {
        cout<<"brew tea"<<endl;
    }
    void pour()
    {
        cout<<"pour into tea cup"<<endl;
    }

};

void doWork(virtualDrink *vd)   // virtualDrink *vd = new Coffee
{
    vd->make();
    delete vd;
}

int main()
{
    doWork(new Coffee);

    doWork(new Tea);
}