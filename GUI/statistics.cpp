#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) : QWidget(parent), ui(new Ui::Statistics)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::on_statistics_return_clicked()
{
    emit on_return();
    this->close();
}
