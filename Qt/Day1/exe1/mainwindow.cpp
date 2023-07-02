#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag = false;

    //一个按钮负责将两个label变成hello world
    //连接函数
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btn()));
    //参数：
    //1. 信号发送者
    //2. 发送的信号
    //3. 接收者
    //4. 相应的槽函数
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btn()));

    //一个点击按钮，控制两个label
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(slot_btn2())  );


    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slot_btn3())  );

    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(slot_btn4())  );

    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(slot_btn5())  );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_btn()
{
    //修改文本内容，把hello变成hello world
    ui->label->setText("hello world");
    ui->label_2->setText("hello world");
}

void MainWindow::slot_btn2()
{
    ui->label_3->setText("hello");
    ui->label_4->setText("world");
}

void MainWindow::slot_btn3()
{
    ui->label_5->setText("Hello world");
    ui->label_6->setText("Hello world");
}

void MainWindow::slot_btn4()
{
    ui->label_5->setText("world");
}


//bool flag = false;
//void MainWindow::slot_btn5()
//{
//    if(flag == false)
//    {
//        flag = true;
//        ui->pushButton_5->setText("On");
//        ui->label_7->setText("on");
//    }
//    else if(flag == true)
//    {
//        flag = false;
//        ui->pushButton_5->setText("Off");
//        ui->label_7->setText("off");
//    }

//}


void MainWindow::slot_btn5()
{
    if(flag == false)
    {
        flag = true;
        ui->pushButton_5->setText("On");
        ui->label_7->setText("on");
    }
    else if(flag == true)
    {
        flag = false;
        ui->pushButton_5->setText("Off");
        ui->label_7->setText("off");
    }

}


