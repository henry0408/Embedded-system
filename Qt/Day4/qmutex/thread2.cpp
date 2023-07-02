#include "thread2.h"

extern int num;
extern QMutex mut;

Thread2::Thread2()
{

}

void Thread2::run()
{
    for(int i = 0; i<100000; i++)
    {
        mut.lock();
        num--;
        mut.unlock();
    }
}

Thread2::~Thread2()
{

}

