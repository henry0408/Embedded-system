#include "mytime.h"

MyTimer::MyTimer(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void MyTimer::getTime()
{
    if(second == 59)
    {
        second = 0;
        minute++;
        if(minute == 60)
        {
            minute = 0;
            hour++;
            if(hour == 24)
            {
                hour = 0;
            }
        }
    }
    else
    {
        second++;
    }

    cout<<hour<<" "<<minute<<" "<<second<<endl;
}