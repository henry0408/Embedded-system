#ifndef THREAD2_H
#define THREAD2_H
#include <QThread>
#include <QMutex>

class Thread2: public QThread
{
public:
    Thread2();
    void run();
    ~Thread2();
};

#endif // THREAD2_H
