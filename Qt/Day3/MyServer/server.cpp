#include "server.h"

Server::Server()
{

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //发送自定义信号
    emit sig_sendSd(socketDescriptor);
}

Server::~Server()
{

}

