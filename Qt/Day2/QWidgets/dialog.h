﻿#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    ~Dialog();

private slots:
    void on_reg_Button_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H