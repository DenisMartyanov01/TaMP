#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions_for_client.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::slot_on_auth_ok()
{
    delete ui_reg;
    this->show();
}
*/
void MainWindow::task_n(int i)
{
    Task1* task1 = new Task1;
    task1->show();
    task1->set_task(i);
    connect(task1, &Task1::on_return, this, &MainWindow::on_return);
    connect(task1, &Task1::send_to_server, this, &MainWindow::slot_send_task);
    this->hide();
}

void MainWindow::on_pushButton_Task1_clicked()
{
    task_n(1);
}

void MainWindow::on_pushButton_Task2_clicked()
{
    task_n(2);
}

void MainWindow::on_pushButton_Task3_clicked()
{
    task_n(3);
}

void MainWindow::slot_stat_error(QString line)
{
    emit signal_stat_error(line);
}

void MainWindow::on_pushButton_Stats_clicked()
{
    Statistics* statistics = new Statistics;
    statistics->show();
    connect(statistics, &Statistics::request_lookmystat, this, &MainWindow::slot_request_lookmystat);
    connect(statistics, &Statistics::request_lookallstat, this, &MainWindow::slot_request_lookallstat);
    connect(statistics, &Statistics::request_sort, this, &MainWindow::slot_request_sort);
    connect(statistics, &Statistics::on_return, this, &MainWindow::on_return);
    connect(this, &MainWindow::signal_received_mystat, statistics, &Statistics::received_mystat);
    connect(this, &MainWindow::signal_received_allstat, statistics, &Statistics::received_allstat);

    this->hide();
}

void MainWindow::on_pushButton_Exit_clicked()
{
    this->close();
}

void MainWindow::on_return()
{
    std::cout << "got into slot\n";
    this->show();
}

void MainWindow::slot_send_task(int i, QString text)
{
    qDebug() << "on_send_task mainwindow slot\n";
    emit send_task(i, text);
}

void MainWindow::slot_request_sort(QString sorti)
{
    emit request_sort_main(sorti);
}

void MainWindow::slot_request_lookmystat()
{
    emit request_lookmystat_main();
}

void MainWindow::slot_request_lookallstat()
{
    emit request_lookallstat_main();
}

void MainWindow::slot_received_mystat(int a, int b, int c)
{
    emit signal_received_mystat(a, b, c);
}

void MainWindow::slot_received_allstat(QString a, QString b, QString c, QString d)
{
    emit signal_received_allstat(a, b, c, d);
}
