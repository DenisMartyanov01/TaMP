/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Task1;
    QPushButton *pushButton_Task3;
    QPushButton *pushButton_Task2;
    QPushButton *pushButton_Stats;
    QPushButton *pushButton_Exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(170, 130, 481, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Task1 = new QPushButton(gridLayoutWidget);
        pushButton_Task1->setObjectName("pushButton_Task1");

        gridLayout->addWidget(pushButton_Task1, 0, 0, 1, 1);

        pushButton_Task3 = new QPushButton(gridLayoutWidget);
        pushButton_Task3->setObjectName("pushButton_Task3");

        gridLayout->addWidget(pushButton_Task3, 0, 2, 1, 1);

        pushButton_Task2 = new QPushButton(gridLayoutWidget);
        pushButton_Task2->setObjectName("pushButton_Task2");

        gridLayout->addWidget(pushButton_Task2, 0, 1, 1, 1);

        pushButton_Stats = new QPushButton(gridLayoutWidget);
        pushButton_Stats->setObjectName("pushButton_Stats");

        gridLayout->addWidget(pushButton_Stats, 1, 0, 1, 1);

        pushButton_Exit = new QPushButton(gridLayoutWidget);
        pushButton_Exit->setObjectName("pushButton_Exit");

        gridLayout->addWidget(pushButton_Exit, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Task1->setText(QCoreApplication::translate("MainWindow", "Newton", nullptr));
        pushButton_Task3->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        pushButton_Task2->setText(QCoreApplication::translate("MainWindow", "Music", nullptr));
        pushButton_Stats->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
