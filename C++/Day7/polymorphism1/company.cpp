#include "company.h"

Company::Company()
{

}

Developer *Company::recruit()
{
    srand(time(0));
    int re = rand()%2;
    Developer* d;
    if(re == 0)
    {
        d = new Manito;
    }
    else
    {
        d = new SmallBird;
    }

    return d;
}

void Company::work(Developer *p)
{
    p->develop();
}

Company::~Company()
{

}

