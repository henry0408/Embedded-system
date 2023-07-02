#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>
#include "dialog.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setpassword(QString pass);
    void setusername(QString usrname);

    ~MainWindow();

private slots:
    bool getpassword();
    bool getusername();
    void on_login_Button_clicked();

    void on_regist_button_clicked();

private:
    Ui::MainWindow *ui;
    QString password;
    QString username;
};

#endif // MAINWINDOW_H
