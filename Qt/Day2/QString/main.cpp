#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //像printf一样输出
    int num = 10;
    qDebug("num is %d",num);

    //像cout一样输出
    qDebug()<<num;


    //拼接
    QString s1 = "hello";
    QString s2 = "world";
    qDebug()<<s1+s2;

    //追加
    s1.append(s2);
    qDebug()<<s1;

    //格式化
    QString s3 = QString("%1 born in %2").arg("xm").arg(1990);
    qDebug()<<s3;

    //数字转字符串
    QString s = QString().setNum(16);
    QString s1 = QString("%1").arg(16);


    //字符串转换


    return a.exec();
}
