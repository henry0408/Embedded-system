#include "thread1.h"

extern int num;     //外部引用全局变量

extern QMutex mut;

Thread1::Thread1()
{

}

void Thread1::run()
{
    for(int i = 0; i<100000; i++)
    {
        mut.lock();
        num++;
        mut.unlock();
    }

}

Thread1::~Thread1()
{

}

