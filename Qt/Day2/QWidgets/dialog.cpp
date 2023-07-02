#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

extern QString usr_name;
extern QString input_pass;
extern QString second_input_pass;

void Dialog::on_reg_Button_clicked()
{
    input_pass = ui->password_line->text();
    second_input_pass = ui->confirm_line->text();

    if(input_pass == second_input_pass)
    {
        ui->reg_result->setText("success");
        usr_name = ui->username_line->text();
        qDebug()<<input_pass;
//        MainWindow *mw = new MainWindow(this);     //注意this的用途：关闭mainwindow则dialog也关闭
//        mw->show();
    }
    else
    {
        ui->reg_result->setText("fail");
    }

}
