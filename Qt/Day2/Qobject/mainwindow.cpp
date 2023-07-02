#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //连接函数
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_bin()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slot_bin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_bin()
{
    //获取当前发送信号的对象
    QObject* send = QObject::sender();

    if(send == ui->pushButton)
    {
        ui->label->setText("1");
    }
    else if(send == ui->pushButton_2)
    {
        ui->label->setText("2");
    }
}
