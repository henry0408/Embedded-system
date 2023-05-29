#ifndef MYTIMER_H
#define MYTIMER_H


class MyTimer
{
private:
    int hour, minite, second;
public:
    MyTimer(int h, int m, int s);
    ~MyTimer();
    void show_time()
    {
        cout<<hour<<minite<<second;
    }
};

#endif // MYTIMER_H
