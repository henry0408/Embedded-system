/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *username_line;
    QLineEdit *password_line;
    QLineEdit *confirm_line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *reg_Button;
    QLabel *reg_result;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(425, 312);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 90, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username_line = new QLineEdit(verticalLayoutWidget);
        username_line->setObjectName(QStringLiteral("username_line"));

        verticalLayout->addWidget(username_line);

        password_line = new QLineEdit(verticalLayoutWidget);
        password_line->setObjectName(QStringLiteral("password_line"));
        password_line->setMaxLength(6);
        password_line->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password_line);

        confirm_line = new QLineEdit(verticalLayoutWidget);
        confirm_line->setObjectName(QStringLiteral("confirm_line"));
        confirm_line->setMaxLength(6);
        confirm_line->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout->addWidget(confirm_line);

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 90, 72, 15));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 120, 72, 15));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 150, 72, 15));
        reg_Button = new QPushButton(Dialog);
        reg_Button->setObjectName(QStringLiteral("reg_Button"));
        reg_Button->setGeometry(QRect(160, 210, 93, 28));
        reg_result = new QLabel(Dialog);
        reg_result->setObjectName(QStringLiteral("reg_result"));
        reg_result->setGeometry(QRect(280, 270, 72, 15));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        password_line->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        confirm_line->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        label->setText(QApplication::translate("Dialog", "\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201", 0));
        label_3->setText(QApplication::translate("Dialog", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        reg_Button->setText(QApplication::translate("Dialog", "\346\263\250\345\206\214", 0));
        reg_result->setText(QApplication::translate("Dialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
