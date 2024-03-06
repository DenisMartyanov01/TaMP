#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui_reg = new auth_reg;
    //ui_reg->show();
    //connect(ui_reg->get_func(), &functions_for_client::on_auth_ok, this, &MainWindow::slot_on_auth_ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Exit_clicked()
{
    this->close();
}
/*
void MainWindow::slot_on_auth_ok()
{
    delete ui_reg;
    this->show();
}
*/
