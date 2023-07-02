#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //默认从mainwindow开始
    MainWindow w;
    w.show();

//    //把起始页面改成dialog
//    Dialog d;
//    d.show();

    return a.exec();
}
