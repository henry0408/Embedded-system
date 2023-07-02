#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");

    //设置主机名称
    db.setHostName("testdb");
    //数据库文件取名
    db.setDatabaseName("testdb.db");

    //打开数据库
    db.open();

    //创建数据表
    createTable();

    //关闭数据库
    //db.close();

}

void MainWindow::createTable()
{
    //创建操作类对象
    QSqlQuery query;
    //创建表,primary key主键,autoincrement自动增长
    bool re = query.exec("create table if not exists user(\
                      userid integer primary key autoincrement,\
                      password varchar(20),\
                      nickname varchar(20),\
                      headid integer\
                      )");
    if(re)
    {
        qDebug()<<"创建表";
    }
    else
        qDebug()<<"创建表失败";
    //插入一个数据，起始id时100001
    query.exec("insert into user values(100000,'abc123','admin',0 )");
}

void MainWindow::insertTable()
{
    //创建操作类对象
    QSqlQuery query;

    //准备sql文,?表示占位符
    query.prepare("insert into user(password,nickname,headid) values(?,?,?)");

    //绑定
    //获取password数据
    QString pass =  ui->lineEdit_nickname_password->text();
    QString nickname = ui->lineEdit_nickname->text();

    query.bindValue(0,pass);
    query.bindValue(1,nickname);
    query.bindValue(2,1);

    //执行sql文
    bool re = query.exec();
    if(re)
    {
        qDebug()<<"插入表";
    }
    else
        qDebug()<<"插入表失败";

    query.exec("SELECT LAST_INSERT_ROWID()");//查询最新插入的id
    if(query.next())    //结果被存入到链表中
    {
        //query.racord()获取一整条记录，value(0)获取到第一个字段的值
        int id = query.record().value(0).toInt();    //第一列
        qDebug()<<id;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //点击注册按钮时，执行插入操作
    insertTable();
}
