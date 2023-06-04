#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Food
{
public:
    virtual void taste()
    {
        cout<<"food"<<endl;
    }
};

class CoolNoodles : public Food
{
public:
    void taste()
    {
        cout<<"cool noodles"<<endl;
    }
};

class FriRibs : public Food
{
public:
    void taste()
    {
        cout<<"FriRibs"<<endl;
    }
};

class HandCake : public Food
{
public:
    void taste()
    {
        cout<<"Hand cake"<<endl;
    }
};

class Teacher
{
public:
    void eat(Food* f)
    {
        f->taste();
    }
};


class Student
{
public:
    Food* buy()
    {
        srand(time(0));
        int re = rand()%3;
        Food *f;
        if(re == 0)
        {
            f = new CoolNoodles;
            return f;
        }
        else if(re == 1)
        {
            f = new FriRibs;
            return f;
        }
        else
        {
            f = new HandCake;
            return  f;
        }
    }
};

int main()
{
    Student xm;
    Teacher t;
    t.eat(xm.buy());
    return 0;
}

