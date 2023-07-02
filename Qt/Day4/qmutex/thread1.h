#ifndef THREAD1_H
#define THREAD1_H

#include <QThread>
#include <QMutex>

class Thread1 : public QThread
{
public:
    Thread1();
    void run();
    ~Thread1();
};

#endif // THREAD1_H
