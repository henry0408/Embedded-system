#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {          //命名空间
class MainWindow;
}

class MainWindow : public QMainWindow       //继承
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:       //槽函数
    void slot_btn();
    void slot_btn2();
    void slot_btn3();
    void slot_btn4();
    void slot_btn5();

private:
    Ui::MainWindow *ui;
    bool flag;      //标志位负责记录灯开/关
};

#endif // MAINWINDOW_H
