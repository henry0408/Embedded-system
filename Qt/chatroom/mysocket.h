#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>


//单例模式
class MySocket: public QTcpSocket
{
    static MySocket* ins;//私有的静态类指针
    MySocket();
    MySocket(const MySocket& o);    //私有的拷贝构造
public:
    static MySocket* getIns();  //公用的静态成员函数(接口），返回值是指针
    ~MySocket();
};

#endif // MYSOCKET_H
