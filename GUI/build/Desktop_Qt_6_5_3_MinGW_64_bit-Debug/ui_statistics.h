/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistics
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Sort;
    QLabel *label_Newton;
    QLabel *label_Music;
    QLabel *label_Graph_meaning;
    QPushButton *statistics_return;
    QLabel *label_error;
    QLabel *label_Newton_meaning;
    QLineEdit *lineEdit_sort;
    QLabel *label_Music_meaning;
    QLabel *label_Graph;
    QPushButton *pushButton_myStat;
    QPushButton *pushButton_allStat;
    QLabel *label_logins;

    void setupUi(QWidget *Statistics)
    {
        if (Statistics->objectName().isEmpty())
            Statistics->setObjectName("Statistics");
        Statistics->resize(800, 600);
        gridLayoutWidget = new QWidget(Statistics);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(180, 130, 421, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Sort = new QPushButton(gridLayoutWidget);
        pushButton_Sort->setObjectName("pushButton_Sort");

        gridLayout->addWidget(pushButton_Sort, 5, 2, 1, 1);

        label_Newton = new QLabel(gridLayoutWidget);
        label_Newton->setObjectName("label_Newton");

        gridLayout->addWidget(label_Newton, 0, 0, 1, 1);

        label_Music = new QLabel(gridLayoutWidget);
        label_Music->setObjectName("label_Music");

        gridLayout->addWidget(label_Music, 1, 0, 1, 1);

        label_Graph_meaning = new QLabel(gridLayoutWidget);
        label_Graph_meaning->setObjectName("label_Graph_meaning");

        gridLayout->addWidget(label_Graph_meaning, 2, 3, 1, 1);

        statistics_return = new QPushButton(gridLayoutWidget);
        statistics_return->setObjectName("statistics_return");

        gridLayout->addWidget(statistics_return, 5, 3, 1, 1);

        label_error = new QLabel(gridLayoutWidget);
        label_error->setObjectName("label_error");

        gridLayout->addWidget(label_error, 4, 1, 1, 2);

        label_Newton_meaning = new QLabel(gridLayoutWidget);
        label_Newton_meaning->setObjectName("label_Newton_meaning");

        gridLayout->addWidget(label_Newton_meaning, 0, 3, 1, 1);

        lineEdit_sort = new QLineEdit(gridLayoutWidget);
        lineEdit_sort->setObjectName("lineEdit_sort");

        gridLayout->addWidget(lineEdit_sort, 6, 2, 1, 1);

        label_Music_meaning = new QLabel(gridLayoutWidget);
        label_Music_meaning->setObjectName("label_Music_meaning");

        gridLayout->addWidget(label_Music_meaning, 1, 3, 1, 1);

        label_Graph = new QLabel(gridLayoutWidget);
        label_Graph->setObjectName("label_Graph");

        gridLayout->addWidget(label_Graph, 2, 0, 1, 1);

        pushButton_myStat = new QPushButton(gridLayoutWidget);
        pushButton_myStat->setObjectName("pushButton_myStat");

        gridLayout->addWidget(pushButton_myStat, 5, 0, 1, 1);

        pushButton_allStat = new QPushButton(gridLayoutWidget);
        pushButton_allStat->setObjectName("pushButton_allStat");

        gridLayout->addWidget(pushButton_allStat, 5, 1, 1, 1);

        label_logins = new QLabel(gridLayoutWidget);
        label_logins->setObjectName("label_logins");

        gridLayout->addWidget(label_logins, 3, 0, 1, 4);


        retranslateUi(Statistics);

        QMetaObject::connectSlotsByName(Statistics);
    } // setupUi

    void retranslateUi(QWidget *Statistics)
    {
        Statistics->setWindowTitle(QCoreApplication::translate("Statistics", "Form", nullptr));
        pushButton_Sort->setText(QCoreApplication::translate("Statistics", "Sort", nullptr));
        label_Newton->setText(QCoreApplication::translate("Statistics", "Newton", nullptr));
        label_Music->setText(QCoreApplication::translate("Statistics", "Music", nullptr));
        label_Graph_meaning->setText(QString());
        statistics_return->setText(QCoreApplication::translate("Statistics", "Return", nullptr));
        label_error->setText(QString());
        label_Newton_meaning->setText(QString());
        label_Music_meaning->setText(QString());
        label_Graph->setText(QCoreApplication::translate("Statistics", "Graph", nullptr));
        pushButton_myStat->setText(QCoreApplication::translate("Statistics", "myStat", nullptr));
        pushButton_allStat->setText(QCoreApplication::translate("Statistics", "allStat", nullptr));
        label_logins->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Statistics: public Ui_Statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
