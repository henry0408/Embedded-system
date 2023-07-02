#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

struct UserData
{
    int i;
};

class MyThread : public QThread
{

    Q_OBJECT

signals:
    void mySignal(UserData i);
public:
    MyThread();
    void run(); //重写run函数，执行线程的逻辑
    ~MyThread();
};

#endif // MYTHREAD_H
