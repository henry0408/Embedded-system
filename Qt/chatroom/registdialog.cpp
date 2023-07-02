#include "registdialog.h"
#include "ui_registdialog.h"


RegistDialog::RegistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistDialog)
{
    ui->setupUi(this);
    socket = MySocket::getIns();

    //接收数据的连接函数
    connect(socket, SIGNAL(readyRead()),this,SLOT(slot_read()) );
}

void RegistDialog::closeEvent(QCloseEvent *)
{
    //断开连接
    disconnect(socket,SIGNAL(readyRead()),this,SLOT(slot_read()) );
}

RegistDialog::~RegistDialog()
{
    delete ui;
}

void RegistDialog::slot_read()
{
    //获取接收信息
    QByteArray data = socket->readAll();

    QString jsonStr = QString::fromLocal8Bit(data);
    qDebug()<<jsonStr;

    //解析
    int id = MsgBuilder::parseRegisterUserReturnMsg(jsonStr);
    //id显示在画面上
    ui->label_id->setNum(id);
}

//注册按钮
void RegistDialog::on_pushButton_regist_clicked()
{
    //获取nickname和密码
    int id = 123;
    QString nickname = ui->lineEdit_nickname->text();
    QString pass = ui->lineEdit_password->text();

    //构建json串
    QString info = MsgBuilder::buildRegisterUserMsg(pass,id,nickname);
//    MsgBuilder::parseRegisterUserMsg(info);

    socket->write(info.toLocal8Bit());

}
