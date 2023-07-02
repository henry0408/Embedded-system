#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setIp();            //设置IP
    server = new Server(this);

    //监听所有IP地址以及端口号，QHostAddress::Any主机所有地址
    server->listen(QHostAddress::Any, 12345);

    //当有新的客户端连接时，server对象会发送newconnection信号
    //connect( server, SIGNAL(newConnection()), this, SLOT(slot_newCon()) );

    //连接函数，自定义信号(发送sd标志)槽函数
    connect(server, SIGNAL(sig_sendSd(qintptr)), this, SLOT(onSigSendSd(qintptr)));
}

void MainWindow::setIp()
{
    //获取主机名称
    QString hostName = QHostInfo::localHostName();

    //获取主机信息
    QHostInfo info = QHostInfo::fromName(hostName);

    //获取主机地址
    QList<QHostAddress> list = info.addresses();

    QString ip;
    //遍历容器
    for(int i = 0; i<list.size();i++)
    {
        //获取协议类型
        if(list[i].protocol() == QAbstractSocket::IPv4Protocol)
        {
            ip +="*";
            ip += list[i].toString();
        }

        //显示在ui上
        ui->label_addr->setText(ip);
    }
}

void MainWindow::dealUserRegister(QString jsonStr)
{
    //解析json
    UserData user = MsgBuilder::parseRegisterUserMsg(jsonStr);

    //创建用于数据库数据传递的结构体类型
    UserEntity e;
    e.nickName = user.nickname;
    e.passwd = user.password;
    e.headId = user.headId;

    //调用数据库
    bool re = UserDao::getIns()->insertTable(e);
    if(re)
    {
        qDebug()<<"注册成功";
    }
    else
    {
        qDebug()<<"注册失败";
    }


//    qDebug()<<user.nickname;
//    qDebug()<<user.password;

    //构建注册返回的json串
    QString str = MsgBuilder::buildRegisterUserReturnMsg(e.userId);
    qDebug()<<str;  //检查是否正确
    //发送给客户端
    socket->write(str.toLocal8Bit());
}

void MainWindow::dealUserLogin(QString jsonStr)
{
    //解析
    UserData user = MsgBuilder::parseLoginMsg(jsonStr);
    //创建用于数据库数据传递的结构体类型
    UserEntity e;
    e.userId = user.id;
    e.passwd = user.password;

    //调用数据库
    bool ok;
    UserDao::getIns()->selectTable(e,ok);

    qDebug()<<ok;
    if(ok)
    {
        qDebug()<<"登录成功";
        //获取数据
        user.nickname = e.nickName;
        user.headId = e.headId;
        //构建登录成功返回的json串
        vector<UserData> friends;
        QString str = MsgBuilder::buildLoginSucReturnMsg(user,friends);
        socket->write(str.toLocal8Bit());
    }
    else
    {
        qDebug()<<"登录失败";
        //构建失败返回的json串
        QString str = MsgBuilder::buildLoginLoseReturnMsg();
        socket->write(str.toLocal8Bit());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::slot_newCon()
//{
//    qDebug()<<"有客户端连接";

//    //获取与客户端通信的套接字
//    socket = server->nextPendingConnection();

//    //断开连接，套接字发送disconnected信号
//    connect(socket,SIGNAL(disconnected()),this,SLOT(slot_disCon()) );

//    //接收数据，套接字会发送readyRead信号
//    connect(socket,SIGNAL(readyRead()),this, SLOT(slot_read()) );

//}

void MainWindow::slot_disCon()
{
    qDebug()<<"客户端已断开";
}

void MainWindow::slot_read()
{
    qDebug()<<"有客户端发来消息了";
    //获取接收数据
    QByteArray data = socket->readAll();
    //QByteString -> QString
    QString jsonstr = QString::fromLocal8Bit(data);
    qDebug()<<jsonstr;


    //获取消息类型后再决定做其他处理
    int type = MsgBuilder::msgType(jsonstr);
    //判断是哪种消息
    switch(type)
    {
    case MsgBuilder::registerUser:  //注册，type为0
        dealUserRegister(jsonstr);
        break;
    case MsgBuilder::login:     //登录
        dealUserLogin(jsonstr);

    default:
        break;
    }


}

void MainWindow::onSigSendSd(qintptr sd)
{
    //创建子线程
}
