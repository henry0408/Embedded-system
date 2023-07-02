#include "mythread.h"

MyThread::MyThread()
{

}

void MyThread::run()
{
    for(int i = 0; i<10; i++)
    {
        qDebug()<<i;
        //创建结构体
        UserData data;
        data.i = i;

        //发送信号
        emit mySignal(data);

        //延时
        sleep(1);
    }
}

MyThread::~MyThread()
{
    qDebug()<<"线程被删掉了";
}


