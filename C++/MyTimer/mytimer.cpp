#include "mytimer.h"

MyTimer::MyTimer(int h, int m, int s)
{
    if(s == 59)
    {
        second = 0;
        m++;
        if(m == 60)
        {
            minite = 0;
            h++;
            if(h == 24)
            {
                hour = 0;
            }
        }
    }
    else
        second++;
}

MyTimer::~MyTimer()
{

}

