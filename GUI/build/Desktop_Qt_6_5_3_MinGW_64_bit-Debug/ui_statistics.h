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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistics
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_allStat;
    QPushButton *pushButton_Sort;
    QLineEdit *lineEdit_sort;
    QPushButton *statistics_return;
    QPushButton *pushButton_myStat;
    QGridLayout *base_table;
    QLabel *label_Graph_meaning;
    QLabel *label_logins;
    QLabel *label_Music;
    QLabel *label_Newton;
    QLabel *label_Graph;
    QLabel *label_Newton_meaning;
    QLabel *label_Music_meaning;
    QLabel *label_error;
    QGridLayout *table;
    QLabel *label_music;
    QLabel *label_graph;
    QListView *list_music;
    QListView *list_graph;
    QLabel *label_username;
    QLabel *label_newton;
    QListView *list_newton;
    QListView *list_username;

    void setupUi(QWidget *Statistics)
    {
        if (Statistics->objectName().isEmpty())
            Statistics->setObjectName("Statistics");
        Statistics->resize(800, 600);
        gridLayoutWidget = new QWidget(Statistics);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(90, 100, 626, 385));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_allStat = new QPushButton(gridLayoutWidget);
        pushButton_allStat->setObjectName("pushButton_allStat");

        gridLayout->addWidget(pushButton_allStat, 8, 1, 1, 1);

        pushButton_Sort = new QPushButton(gridLayoutWidget);
        pushButton_Sort->setObjectName("pushButton_Sort");

        gridLayout->addWidget(pushButton_Sort, 8, 2, 1, 1);

        lineEdit_sort = new QLineEdit(gridLayoutWidget);
        lineEdit_sort->setObjectName("lineEdit_sort");

        gridLayout->addWidget(lineEdit_sort, 9, 2, 1, 1);

        statistics_return = new QPushButton(gridLayoutWidget);
        statistics_return->setObjectName("statistics_return");

        gridLayout->addWidget(statistics_return, 8, 3, 1, 1);

        pushButton_myStat = new QPushButton(gridLayoutWidget);
        pushButton_myStat->setObjectName("pushButton_myStat");

        gridLayout->addWidget(pushButton_myStat, 8, 0, 1, 1);

        base_table = new QGridLayout();
        base_table->setObjectName("base_table");
        label_Graph_meaning = new QLabel(gridLayoutWidget);
        label_Graph_meaning->setObjectName("label_Graph_meaning");

        base_table->addWidget(label_Graph_meaning, 2, 1, 1, 1);

        label_logins = new QLabel(gridLayoutWidget);
        label_logins->setObjectName("label_logins");

        base_table->addWidget(label_logins, 4, 0, 1, 2);

        label_Music = new QLabel(gridLayoutWidget);
        label_Music->setObjectName("label_Music");

        base_table->addWidget(label_Music, 1, 0, 1, 1);

        label_Newton = new QLabel(gridLayoutWidget);
        label_Newton->setObjectName("label_Newton");

        base_table->addWidget(label_Newton, 0, 0, 1, 1);

        label_Graph = new QLabel(gridLayoutWidget);
        label_Graph->setObjectName("label_Graph");

        base_table->addWidget(label_Graph, 2, 0, 1, 1);

        label_Newton_meaning = new QLabel(gridLayoutWidget);
        label_Newton_meaning->setObjectName("label_Newton_meaning");

        base_table->addWidget(label_Newton_meaning, 0, 1, 1, 1);

        label_Music_meaning = new QLabel(gridLayoutWidget);
        label_Music_meaning->setObjectName("label_Music_meaning");

        base_table->addWidget(label_Music_meaning, 1, 1, 1, 1);

        label_error = new QLabel(gridLayoutWidget);
        label_error->setObjectName("label_error");

        base_table->addWidget(label_error, 5, 0, 1, 2);


        gridLayout->addLayout(base_table, 6, 1, 1, 2);

        table = new QGridLayout();
        table->setObjectName("table");
        label_music = new QLabel(gridLayoutWidget);
        label_music->setObjectName("label_music");

        table->addWidget(label_music, 0, 2, 1, 1);

        label_graph = new QLabel(gridLayoutWidget);
        label_graph->setObjectName("label_graph");

        table->addWidget(label_graph, 0, 3, 1, 1);

        list_music = new QListView(gridLayoutWidget);
        list_music->setObjectName("list_music");

        table->addWidget(list_music, 2, 2, 1, 1);

        list_graph = new QListView(gridLayoutWidget);
        list_graph->setObjectName("list_graph");

        table->addWidget(list_graph, 2, 3, 1, 1);

        label_username = new QLabel(gridLayoutWidget);
        label_username->setObjectName("label_username");

        table->addWidget(label_username, 0, 0, 1, 1);

        label_newton = new QLabel(gridLayoutWidget);
        label_newton->setObjectName("label_newton");

        table->addWidget(label_newton, 0, 1, 1, 1);

        list_newton = new QListView(gridLayoutWidget);
        list_newton->setObjectName("list_newton");

        table->addWidget(list_newton, 2, 1, 1, 1);

        list_username = new QListView(gridLayoutWidget);
        list_username->setObjectName("list_username");

        table->addWidget(list_username, 2, 0, 1, 1);


        gridLayout->addLayout(table, 7, 0, 1, 4);


        retranslateUi(Statistics);

        QMetaObject::connectSlotsByName(Statistics);
    } // setupUi

    void retranslateUi(QWidget *Statistics)
    {
        Statistics->setWindowTitle(QCoreApplication::translate("Statistics", "Form", nullptr));
        pushButton_allStat->setText(QCoreApplication::translate("Statistics", "allStat", nullptr));
        pushButton_Sort->setText(QCoreApplication::translate("Statistics", "Sort", nullptr));
        statistics_return->setText(QCoreApplication::translate("Statistics", "Return", nullptr));
        pushButton_myStat->setText(QCoreApplication::translate("Statistics", "myStat", nullptr));
        label_Graph_meaning->setText(QString());
        label_logins->setText(QString());
        label_Music->setText(QCoreApplication::translate("Statistics", "Music", nullptr));
        label_Newton->setText(QCoreApplication::translate("Statistics", "Newton", nullptr));
        label_Graph->setText(QCoreApplication::translate("Statistics", "Graph", nullptr));
        label_Newton_meaning->setText(QString());
        label_Music_meaning->setText(QString());
        label_error->setText(QString());
        label_music->setText(QCoreApplication::translate("Statistics", "Music", nullptr));
        label_graph->setText(QCoreApplication::translate("Statistics", "Graph", nullptr));
        label_username->setText(QCoreApplication::translate("Statistics", "username", nullptr));
        label_newton->setText(QCoreApplication::translate("Statistics", "Newton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistics: public Ui_Statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
