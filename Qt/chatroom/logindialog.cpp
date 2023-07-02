#include "logindialog.h"
#include "ui_logindialog.h"
#include "registdialog.h"

//外部引用全局变量
extern QString id;
extern QString pass;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    socket = MySocket::getIns();

    //连接函数，连接成功发送connected信号
    connect(socket,SIGNAL(connected()),this,SLOT(slot_con()) ); //this表示当前窗口
    connect(socket,SIGNAL(readyRead()),this,SLOT(slot_read()) );

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::slot_con()
{
    qDebug()<<"连接成功";
    ui->lineEdit_username->setEnabled(true);
    ui->lineEdit_password->setEnabled(true);
    ui->pushButton_login->setEnabled(true);
    ui->pushButton_regist->setEnabled(true);
}

void LoginDialog::slot_read()
{
    //获取json
    QByteArray data = socket->readAll();
    QString jsonstr = QString::fromLocal8Bit(data);
    qDebug()<<jsonstr;

    //获取消息类型
    int type = MsgBuilder::msgType(jsonstr);

    qDebug()<<"Type is:";
    qDebug()<<type;

    //判断消息类型
    switch (type) {
    case MsgBuilder::loginSucReturn: //登录成功，type=3
        //处理登录成功
        QMessageBox::warning(this,"提示","登录成功");
        break;
    case MsgBuilder::loginLoseReturn: //登录失败，type=4
        //处理登录失败
        QMessageBox::information(this,"提示","登陆失败 请确认用户名/密码");
        break;
    default:
        break;
    }
}


//连接IP按钮
void LoginDialog::on_pushButton_connect_clicked()
{
    //获取line edit中的内容
    QString ip = ui->lineEdit_ip->text();
    //连接
    socket->connectToHost(QHostAddress(ip),12345);
}

//注册按钮
void LoginDialog::on_pushButton_regist_clicked()
{
    RegistDialog *reg = new RegistDialog(this);

    //先要断开登录界面的连接函数，断开哪个信号，就断开哪个槽函数
    disconnect(socket,SIGNAL(readyRead()),this,SLOT(slot_read()) );

    //带有阻塞效果的显示页面
    reg->exec();

    //连接回登录界面的函数
    connect(socket,SIGNAL(readyRead()),this,SLOT(slot_read()) );
}

//登录按钮
void LoginDialog::on_pushButton_login_clicked()
{
    //获取用户输入的用户名和密码
    QString id = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //构建json
    QString jsonstr = MsgBuilder::buildLoginMsg(id.toInt(),password);
    qDebug()<<jsonstr;

    //发送给服务器
    socket->write(jsonstr.toLocal8Bit());

}
