/********************************************************************************
** Form generated from reading UI file 'auth_reg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_REG_H
#define UI_AUTH_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth_reg
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_email;
    QLabel *label_password;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_email;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_login;
    QPushButton *pushButton_change;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *auth_reg)
    {
        if (auth_reg->objectName().isEmpty())
            auth_reg->setObjectName("auth_reg");
        auth_reg->resize(800, 600);
        verticalLayoutWidget = new QWidget(auth_reg);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(130, 180, 511, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_email = new QLabel(verticalLayoutWidget);
        label_email->setObjectName("label_email");

        gridLayout->addWidget(label_email, 2, 0, 1, 1);

        label_password = new QLabel(verticalLayoutWidget);
        label_password->setObjectName("label_password");

        gridLayout->addWidget(label_password, 1, 0, 1, 1);

        label_login = new QLabel(verticalLayoutWidget);
        label_login->setObjectName("label_login");

        gridLayout->addWidget(label_login, 0, 0, 1, 1);

        lineEdit_login = new QLineEdit(verticalLayoutWidget);
        lineEdit_login->setObjectName("lineEdit_login");

        gridLayout->addWidget(lineEdit_login, 0, 1, 1, 1);

        lineEdit_password = new QLineEdit(verticalLayoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        lineEdit_email = new QLineEdit(verticalLayoutWidget);
        lineEdit_email->setObjectName("lineEdit_email");

        gridLayout->addWidget(lineEdit_email, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_reg = new QPushButton(verticalLayoutWidget);
        pushButton_reg->setObjectName("pushButton_reg");

        horizontalLayout->addWidget(pushButton_reg);

        pushButton_login = new QPushButton(verticalLayoutWidget);
        pushButton_login->setObjectName("pushButton_login");

        horizontalLayout->addWidget(pushButton_login);

        pushButton_change = new QPushButton(verticalLayoutWidget);
        pushButton_change->setObjectName("pushButton_change");

        horizontalLayout->addWidget(pushButton_change);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_exit = new QPushButton(auth_reg);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(650, 330, 122, 29));

        retranslateUi(auth_reg);

        QMetaObject::connectSlotsByName(auth_reg);
    } // setupUi

    void retranslateUi(QWidget *auth_reg)
    {
        auth_reg->setWindowTitle(QCoreApplication::translate("auth_reg", "Form", nullptr));
        label_email->setText(QCoreApplication::translate("auth_reg", "E-mail", nullptr));
        label_password->setText(QCoreApplication::translate("auth_reg", "Password", nullptr));
        label_login->setText(QCoreApplication::translate("auth_reg", "Login", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("auth_reg", "Sign up", nullptr));
        pushButton_login->setText(QCoreApplication::translate("auth_reg", "Sign in", nullptr));
        pushButton_change->setText(QCoreApplication::translate("auth_reg", "Sign up", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("auth_reg", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class auth_reg: public Ui_auth_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_REG_H
