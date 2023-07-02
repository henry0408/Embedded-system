#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QMessageBox>  //消息提示框
#include "CJsonObject.hpp"
#include "registdialog.h"
#include "mysocket.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public slots:
    void slot_con();        //为连接成功写的槽函数
    void slot_read();     //为接收数据写的槽函数

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_regist_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::LoginDialog *ui;
    MySocket *socket;
};

#endif // LOGINDIALOG_H
