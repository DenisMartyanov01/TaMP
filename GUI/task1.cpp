#include "task1.h"
#include "ui_task1.h"

Task1::Task1(QWidget *parent) : QWidget(parent), ui(new Ui::Task1)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

Task1::~Task1()
{
    delete ui;
}


void Task1::on_task1_return_clicked()
{
    emit on_return();
    this->close();
}

