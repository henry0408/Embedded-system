#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slot_my(UserData i);
private:
    Ui::MainWindow *ui;
    MyThread *t;    //线程指针
};

#endif // MAINWINDOW_H
