#ifndef REGISTDIALOG_H
#define REGISTDIALOG_H

#include <QDialog>
#include "mysocket.h"
#include "MsgBuilder.h"

namespace Ui {
class RegistDialog;
}

class RegistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistDialog(QWidget *parent = 0);
    void closeEvent(QCloseEvent *);     //重写关闭事件
    ~RegistDialog();

public slots:
    void slot_read();       //接收信息的槽函数

private slots:
    void on_pushButton_regist_clicked();

private:
    Ui::RegistDialog *ui;
    MySocket *socket;
};

#endif // REGISTDIALOG_H
