/********************************************************************************
** Form generated from reading UI file 'task1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_H
#define UI_TASK1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task1
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit3_Task1;
    QLineEdit *lineEdit2_Task1;
    QLabel *label_Task2;
    QLineEdit *lineEdit_Task1;
    QLabel *label_Task3;
    QLineEdit *lineEdit4_Task1;
    QLineEdit *lineEdit5_Task1;
    QLabel *label_Task1;
    QLabel *label2_Task1;
    QPushButton *task1_return;
    QPushButton *pushButton_Send;
    QLineEdit *lineEdit_Task3;
    QLineEdit *lineEdit2_Task3;
    QLineEdit *lineEdit_Task2;
    QLineEdit *lineEdit2_Task2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Result;
    QLabel *label_Result_meaning;

    void setupUi(QWidget *Task1)
    {
        if (Task1->objectName().isEmpty())
            Task1->setObjectName("Task1");
        Task1->resize(800, 600);
        gridLayoutWidget = new QWidget(Task1);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(180, 80, 461, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit3_Task1 = new QLineEdit(gridLayoutWidget);
        lineEdit3_Task1->setObjectName("lineEdit3_Task1");

        gridLayout->addWidget(lineEdit3_Task1, 0, 4, 1, 1);

        lineEdit2_Task1 = new QLineEdit(gridLayoutWidget);
        lineEdit2_Task1->setObjectName("lineEdit2_Task1");

        gridLayout->addWidget(lineEdit2_Task1, 0, 2, 1, 2);

        label_Task2 = new QLabel(gridLayoutWidget);
        label_Task2->setObjectName("label_Task2");
        label_Task2->setEnabled(true);

        gridLayout->addWidget(label_Task2, 2, 0, 1, 1);

        lineEdit_Task1 = new QLineEdit(gridLayoutWidget);
        lineEdit_Task1->setObjectName("lineEdit_Task1");
        lineEdit_Task1->setEnabled(true);
        lineEdit_Task1->setFrame(true);
        lineEdit_Task1->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_Task1, 0, 1, 1, 1);

        label_Task3 = new QLabel(gridLayoutWidget);
        label_Task3->setObjectName("label_Task3");
        label_Task3->setEnabled(true);

        gridLayout->addWidget(label_Task3, 3, 0, 1, 1);

        lineEdit4_Task1 = new QLineEdit(gridLayoutWidget);
        lineEdit4_Task1->setObjectName("lineEdit4_Task1");

        gridLayout->addWidget(lineEdit4_Task1, 1, 1, 1, 2);

        lineEdit5_Task1 = new QLineEdit(gridLayoutWidget);
        lineEdit5_Task1->setObjectName("lineEdit5_Task1");

        gridLayout->addWidget(lineEdit5_Task1, 1, 3, 1, 2);

        label_Task1 = new QLabel(gridLayoutWidget);
        label_Task1->setObjectName("label_Task1");
        label_Task1->setEnabled(true);

        gridLayout->addWidget(label_Task1, 0, 0, 1, 1);

        label2_Task1 = new QLabel(gridLayoutWidget);
        label2_Task1->setObjectName("label2_Task1");
        label2_Task1->setEnabled(true);

        gridLayout->addWidget(label2_Task1, 1, 0, 1, 1);

        task1_return = new QPushButton(gridLayoutWidget);
        task1_return->setObjectName("task1_return");

        gridLayout->addWidget(task1_return, 4, 3, 1, 2);

        pushButton_Send = new QPushButton(gridLayoutWidget);
        pushButton_Send->setObjectName("pushButton_Send");

        gridLayout->addWidget(pushButton_Send, 4, 1, 1, 2);

        lineEdit_Task3 = new QLineEdit(gridLayoutWidget);
        lineEdit_Task3->setObjectName("lineEdit_Task3");
        lineEdit_Task3->setEnabled(true);

        gridLayout->addWidget(lineEdit_Task3, 3, 3, 1, 2);

        lineEdit2_Task3 = new QLineEdit(gridLayoutWidget);
        lineEdit2_Task3->setObjectName("lineEdit2_Task3");

        gridLayout->addWidget(lineEdit2_Task3, 3, 1, 1, 2);

        lineEdit_Task2 = new QLineEdit(gridLayoutWidget);
        lineEdit_Task2->setObjectName("lineEdit_Task2");
        lineEdit_Task2->setEnabled(true);

        gridLayout->addWidget(lineEdit_Task2, 2, 1, 1, 2);

        lineEdit2_Task2 = new QLineEdit(gridLayoutWidget);
        lineEdit2_Task2->setObjectName("lineEdit2_Task2");

        gridLayout->addWidget(lineEdit2_Task2, 2, 3, 1, 2);

        horizontalLayoutWidget = new QWidget(Task1);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(270, 330, 251, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_Result = new QLabel(horizontalLayoutWidget);
        label_Result->setObjectName("label_Result");

        horizontalLayout->addWidget(label_Result);

        label_Result_meaning = new QLabel(horizontalLayoutWidget);
        label_Result_meaning->setObjectName("label_Result_meaning");

        horizontalLayout->addWidget(label_Result_meaning);


        retranslateUi(Task1);

        QMetaObject::connectSlotsByName(Task1);
    } // setupUi

    void retranslateUi(QWidget *Task1)
    {
        Task1->setWindowTitle(QCoreApplication::translate("Task1", "Form", nullptr));
        label_Task2->setText(QCoreApplication::translate("Task1", "Music", nullptr));
        label_Task3->setText(QCoreApplication::translate("Task1", "Graph", nullptr));
        label_Task1->setText(QCoreApplication::translate("Task1", "Newton", nullptr));
        label2_Task1->setText(QCoreApplication::translate("Task1", "Range", nullptr));
        task1_return->setText(QCoreApplication::translate("Task1", "Return", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("Task1", "Send", nullptr));
        label_Result->setText(QCoreApplication::translate("Task1", "Result:", nullptr));
        label_Result_meaning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Task1: public Ui_Task1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_H
