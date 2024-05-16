#include "task2.h"
#include "ui_task2.h"

Task2::Task2(QWidget *parent) : QWidget(parent), ui(new Ui::Task2)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

Task2::~Task2()
{
    delete ui;
}

void Task2::on_task2_return_clicked()
{
    emit on_return();
    this->close();
}
