#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //注册新类型
    qRegisterMetaType<UserData>("UserData");

    t = new MyThread;
    t->start();

    //连接函数
    connect(t,SIGNAL(finished()),t,SLOT(deleteLater()) );
    //自定义信号的连接函数
    connect(t,SIGNAL(mySignal(UserData)),this,SLOT(slot_my(UserData)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_my(UserData data)
{
    ui->label->setNum(data.i);
}
