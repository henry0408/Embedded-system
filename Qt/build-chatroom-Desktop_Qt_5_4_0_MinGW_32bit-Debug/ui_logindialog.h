/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_ip;
    QLabel *label_ip;
    QLabel *label_password;
    QLabel *label_username;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_login;
    QPushButton *pushButton_regist;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(720, 520);
        gridLayoutWidget = new QWidget(LoginDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 140, 351, 241));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        gridLayoutWidget->setFont(font);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_password = new QLineEdit(gridLayoutWidget);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEnabled(false);
        lineEdit_password->setFont(font);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 2, 1, 1, 1);

        lineEdit_username = new QLineEdit(gridLayoutWidget);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setEnabled(false);
        lineEdit_username->setFont(font);

        gridLayout->addWidget(lineEdit_username, 1, 1, 1, 1);

        lineEdit_ip = new QLineEdit(gridLayoutWidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setFont(font);

        gridLayout->addWidget(lineEdit_ip, 0, 1, 1, 1);

        label_ip = new QLabel(gridLayoutWidget);
        label_ip->setObjectName(QStringLiteral("label_ip"));
        label_ip->setFont(font);

        gridLayout->addWidget(label_ip, 0, 0, 1, 1);

        label_password = new QLabel(gridLayoutWidget);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setFont(font);

        gridLayout->addWidget(label_password, 2, 0, 1, 1);

        label_username = new QLabel(gridLayoutWidget);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setFont(font);

        gridLayout->addWidget(label_username, 1, 0, 1, 1);

        pushButton_connect = new QPushButton(LoginDialog);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(510, 160, 93, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_connect->setFont(font1);
        pushButton_login = new QPushButton(LoginDialog);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setEnabled(false);
        pushButton_login->setGeometry(QRect(90, 420, 93, 28));
        pushButton_regist = new QPushButton(LoginDialog);
        pushButton_regist->setObjectName(QStringLiteral("pushButton_regist"));
        pushButton_regist->setEnabled(false);
        pushButton_regist->setGeometry(QRect(400, 430, 93, 28));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        lineEdit_password->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        lineEdit_username->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", 0));
        lineEdit_ip->setText(QApplication::translate("LoginDialog", "192.168.31.239", 0));
        label_ip->setText(QApplication::translate("LoginDialog", "IP:", 0));
        label_password->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        label_username->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0));
        pushButton_connect->setText(QApplication::translate("LoginDialog", "\350\277\236\346\216\245", 0));
        pushButton_login->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
        pushButton_regist->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
