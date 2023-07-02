#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostInfo>
#include <QHostAddress>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include "MsgBuilder.h"
#include "userdao.h"
#include "server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setIp();   //设置IP

    ~MainWindow();

public slots:
    void slot_newCon(); //客户端连接时的槽函数
    void slot_disCon(); //断开连接时的槽函数
    void slot_read();   //接收客户端信息的槽函数
    void onSigSendSd(qintptr sd);   //多线程客户端连接时的槽函数

private:
    Ui::MainWindow *ui;
    Server *server;
    //Server *socket;

};

#endif // MAINWINDOW_H
