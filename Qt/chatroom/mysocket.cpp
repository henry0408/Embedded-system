#include "mysocket.h"

MySocket* MySocket::ins = NULL; //懒汉模式

MySocket::MySocket()
{

}

MySocket::MySocket(const MySocket &o)
{

}

MySocket *MySocket::getIns()
{
    if(ins == NULL)
    {
        ins = new MySocket;
    }
    return ins;
}

MySocket::~MySocket()
{

}

