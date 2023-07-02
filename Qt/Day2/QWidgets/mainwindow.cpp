#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getpassword()
{
    QString input_password;
    input_password = ui->password_line->text();

    if(input_password == password)
    {
        return true;
    }
    return false;
}

bool MainWindow::getusername()
{
    QString input_username;
    input_username = ui->username_line->text();

    if(input_username== username)
    {
        return true;
    }
    return false;
}


void MainWindow::on_login_Button_clicked()
{
    if(getusername()&& getpassword())
        ui->result_label->setText("登录成功");
    else
        ui->result_label->setText("登录失败");
}

void MainWindow::setpassword(QString pass)
{
    this->password = pass;
}

void MainWindow::setusername(QString usrname)
{
    username = usrname;
}

void MainWindow::on_regist_button_clicked()
{
    //页面跳转
    Dialog *reg = new Dialog(this);     //注意this的用途：关闭mainwindow则dialog也关闭
    reg->show();
    setpassword(reg->input_pass);
    qDebug()<<reg->input_pass;
    setusername(reg->usr_name);
}


