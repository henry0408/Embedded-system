#include "socketthread.h"

SocketThread::SocketThread(qintptr sd):QThread(0),sd(sd)
{
    isRun = true;
    isRead = false;
}

void SocketThread::run()
{
    //根据sd标志 获取套接字
    socket = new QTcpSocket;
    socket->setSocketDescriptor(sd);

    //连接函数
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));

    //事件循环
    while (isRun) {     //是否连接状态
        if(isRead)      //是否来消息
        {
            //获取接收消息
            QByteArray data = socket->readAll();
            //QByteArray -> QString
            QString jsonstr = QString::fromLocal8Bit(data);
            qDebug()<<jsonstr;

            //添加到消息队列
            mutex.lock();
            msgQueue.push(jsonstr);
            mutex.unlock();

            isRead = false;
        }
        //判断队列是否为空
        while(!msgQueue.empty())
        {
            QString str = msgQueue.front();
            mutex.lock();
            msgQueue.pop();
            mutex.unlock();

            //获取消息类型后再决定做其他处理
            int type = MsgBuilder::msgType(jsonstr);
            //判断是哪种消息
            switch(type)
            {
            case MsgBuilder::registerUser:  //注册，type为0
                dealUserRegister(jsonstr);
                break;
            case MsgBuilder::login:     //登录
                dealUserLogin(jsonstr);

            default:
                break;
            }
        }

        socket->waitForReadyRead(10);   //单位是毫秒
    }
    //关闭套接字
    socket->close();
}

SocketThread::~SocketThread()
{
    qDebug()<<"shan";
}

void SocketThread::onDisconnect()
{
    qDebug()<<"断开连接！";
    isRun = false;
}

void SocketThread::onReadyRead()
{
    qDebug()<<"来消息啦！";
    isRead = true;
}
