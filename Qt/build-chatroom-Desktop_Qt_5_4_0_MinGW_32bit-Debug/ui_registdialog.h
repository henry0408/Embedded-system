/********************************************************************************
** Form generated from reading UI file 'registdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTDIALOG_H
#define UI_REGISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistDialog
{
public:
    QLabel *label_title;
    QLineEdit *lineEdit_nickname;
    QLineEdit *lineEdit_password;
    QLabel *label_nickname;
    QLabel *label_password;
    QLabel *label_id;
    QPushButton *pushButton_regist;

    void setupUi(QDialog *RegistDialog)
    {
        if (RegistDialog->objectName().isEmpty())
            RegistDialog->setObjectName(QStringLiteral("RegistDialog"));
        RegistDialog->resize(720, 520);
        label_title = new QLabel(RegistDialog);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(130, 70, 471, 51));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(16);
        label_title->setFont(font);
        lineEdit_nickname = new QLineEdit(RegistDialog);
        lineEdit_nickname->setObjectName(QStringLiteral("lineEdit_nickname"));
        lineEdit_nickname->setGeometry(QRect(250, 210, 200, 40));
        lineEdit_password = new QLineEdit(RegistDialog);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(250, 290, 200, 40));
        label_nickname = new QLabel(RegistDialog);
        label_nickname->setObjectName(QStringLiteral("label_nickname"));
        label_nickname->setGeometry(QRect(120, 210, 120, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        label_nickname->setFont(font1);
        label_password = new QLabel(RegistDialog);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(120, 280, 120, 41));
        label_password->setFont(font1);
        label_id = new QLabel(RegistDialog);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setGeometry(QRect(120, 390, 100, 30));
        pushButton_regist = new QPushButton(RegistDialog);
        pushButton_regist->setObjectName(QStringLiteral("pushButton_regist"));
        pushButton_regist->setGeometry(QRect(390, 390, 93, 28));

        retranslateUi(RegistDialog);

        QMetaObject::connectSlotsByName(RegistDialog);
    } // setupUi

    void retranslateUi(QDialog *RegistDialog)
    {
        RegistDialog->setWindowTitle(QApplication::translate("RegistDialog", "Dialog", 0));
        label_title->setText(QApplication::translate("RegistDialog", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\345\222\214\345\257\206\347\240\201\357\274\214\346\263\250\345\206\214\346\210\220\345\212\237\350\277\224\345\233\236id\345\217\267", 0));
        lineEdit_nickname->setPlaceholderText(QApplication::translate("RegistDialog", "\350\257\267\350\276\223\345\205\245\346\230\265\347\247\260", 0));
        lineEdit_password->setPlaceholderText(QApplication::translate("RegistDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        label_nickname->setText(QApplication::translate("RegistDialog", "\346\230\265\347\247\260", 0));
        label_password->setText(QApplication::translate("RegistDialog", "\345\257\206\347\240\201", 0));
        label_id->setText(QApplication::translate("RegistDialog", "\350\277\224\345\233\236id", 0));
        pushButton_regist->setText(QApplication::translate("RegistDialog", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class RegistDialog: public Ui_RegistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTDIALOG_H
