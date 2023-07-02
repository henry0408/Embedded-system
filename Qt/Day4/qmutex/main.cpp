#include <QCoreApplication>
#include "thread1.h"
#include "thread2.h"
#include <QDebug>
#include <QMutex>

int num = 0;

//创建互斥锁
QMutex mut;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Thread1 t1;
    Thread2 t2;

    t1.start();
    t2.start();

//    t1.run();
//    t2.run();

    //阻塞等待
    t1.wait();
    t2.wait();


    //
    qDebug()<<num;

    return a.exec();
}
