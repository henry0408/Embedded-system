#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>


//多线程并发服务器
class Server : public QTcpServer
{
    Q_OBJECT
signals:
    void newConnectionForThread(qintptr sd);
public:
    Server(QObject *parent = 0);
    //重写 incomingConnection函数 socketDescriptor: sd标志或者套接字描述
    void incomingConnection(qintptr socketDescriptor);
    ~Server();

signals:
    void sig_sendSd(qintptr socketDescriptor);
};

#endif // SERVER_H
