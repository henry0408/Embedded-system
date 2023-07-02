#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QMutex>
#include <queue>

using namespace std;

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(qintptr sd);
    void run();
    void dealUserRegister(QString jsonStr); //处理用户注册
    void dealUserLogin(QString jsonStr);    //处理用户登录
    ~SocketThread();
public slots:
    void onDisconnect();//断开连接的槽函数
    void onReadyRead();//接收信息的槽函数
private:
    qintptr sd;//定义sd标志
    QTcpSocket *socket;//定义套接字指针
    bool isRun;
    bool isRead;
    queue<QString> msgQueue;
    QMutex mutex;
};

#endif // SOCKETTHREAD_H
