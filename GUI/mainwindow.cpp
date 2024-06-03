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
    connect(task1, &Task1::send_to_server, this, &MainWindow::on_send_task);
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


void MainWindow::on_pushButton_Stats_clicked()
{
    Statistics* statistics = new Statistics;
    statistics->show();
    connect(statistics, &Statistics::request_lookmystat, this, &MainWindow::on_request_lookmystat);
    connect(statistics, &Statistics::request_lookallstat, this, &MainWindow::on_request_lookallstat);
    connect(statistics, &Statistics::request_sort, this, &MainWindow::on_request_sort);
    connect(statistics, &Statistics::on_return, this, &MainWindow::on_return);
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

void MainWindow::on_send_task(int i, QString text)
{
    qDebug() << "on_send_task mainwindow slot\n";
    emit send_task(i, text);
}

void MainWindow::on_request_sort(QString sorti)
{
    emit request_sort_main(sorti);
}

void MainWindow::on_request_lookmystat()
{
    emit request_lookmystat_main();
}

void MainWindow::on_request_lookallstat()
{
    emit request_lookallstat_main();
}
