#include "task3.h"
#include "ui_task3.h"

Task3::Task3(QWidget *parent) : QWidget(parent), ui(new Ui::Task3)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

Task3::~Task3()
{
    delete ui;
}

void Task3::on_task3_return_clicked()
{
    emit on_return();
    this->close();
}
