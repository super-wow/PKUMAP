/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QLabel *label_image;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *btn_return;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_passwd;
    QLineEdit *lineEdit_surepasswd;

    void setupUi(QWidget *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(376, 305);
        Signup->setMinimumSize(QSize(376, 305));
        Signup->setMaximumSize(QSize(376, 305));
        Signup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_image = new QLabel(Signup);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(9, 11, 171, 281));
        label_3 = new QLabel(Signup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 30, 111, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(Signup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 70, 71, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5 = new QLabel(Signup);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 120, 61, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_6 = new QLabel(Signup);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 170, 111, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(Signup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 230, 80, 21));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));
        btn_return = new QPushButton(Signup);
        btn_return->setObjectName("btn_return");
        btn_return->setGeometry(QRect(219, 260, 81, 21));
        btn_return->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));
        lineEdit_username = new QLineEdit(Signup);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(200, 90, 113, 20));
        lineEdit_username->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_passwd = new QLineEdit(Signup);
        lineEdit_passwd->setObjectName("lineEdit_passwd");
        lineEdit_passwd->setGeometry(QRect(200, 140, 113, 20));
        lineEdit_passwd->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_surepasswd = new QLineEdit(Signup);
        lineEdit_surepasswd->setObjectName("lineEdit_surepasswd");
        lineEdit_surepasswd->setGeometry(QRect(200, 190, 113, 20));
        lineEdit_surepasswd->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QWidget *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Form", nullptr));
        label_image->setText(QCoreApplication::translate("Signup", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Signup", "Welcome", nullptr));
        label_4->setText(QCoreApplication::translate("Signup", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("Signup", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("Signup", "Ensure your password:", nullptr));
        pushButton->setText(QCoreApplication::translate("Signup", "Sure", nullptr));
        btn_return->setText(QCoreApplication::translate("Signup", "Return login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
