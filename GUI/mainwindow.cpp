#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_pushButton_Task1_clicked()
{
    this->task1 = new Task1;
    this->task1->show();
    connect(this->task1, &Task1::on_return, this, &MainWindow::on_return);
    this->hide();
}

void MainWindow::on_pushButton_Task2_clicked()
{
    this->task2 = new Task2;
    this->task2->show();
    connect(this->task2, &Task2::on_return, this, &MainWindow::on_return);
    this->hide();
}

void MainWindow::on_pushButton_Task3_clicked()
{
    this->task3 = new Task3;
    this->task3->show();
    connect(this->task3, &Task3::on_return, this, &MainWindow::on_return);
    this->hide();
}

void MainWindow::on_pushButton_Stats_clicked()
{
    this->statistics = new Statistics;
    this->statistics->show();
    connect(this->statistics, &Statistics::on_return, this, &MainWindow::on_return);
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
