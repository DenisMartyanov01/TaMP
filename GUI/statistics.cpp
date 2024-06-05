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


void Statistics::on_pushButton_myStat_clicked()
{
    this->ui->label_error->setText("");
    this->ui->label_logins->setText("");
    emit request_lookmystat();
}


void Statistics::on_pushButton_allStat_clicked()
{
    this->ui->label_error->setText("");
    this->ui->label_logins->setText("");
    emit request_lookallstat();
}


void Statistics::on_pushButton_Sort_clicked()
{
    this->ui->label_error->setText("");
    this->ui->label_logins->setText("");
    emit request_sort(this->ui->lineEdit_sort->text());
}

void Statistics::slot_error(QString line)
{
    this->ui->label_error->setText(line);
}

void Statistics::received_mystat(int graph, int music, int newton)
{
    this->ui->label_Graph_meaning->setText(QString::number(graph));
    this->ui->label_Music_meaning->setText(QString::number(music));
    this->ui->label_Newton_meaning->setText(QString::number(newton));
}

void Statistics::received_allstat(QString logins, QString graph, QString music, QString newton)
{
    this->ui->label_logins->setText(logins);
    this->ui->label_Graph_meaning->setText(graph);
    this->ui->label_Music_meaning->setText(music);
    this->ui->label_Newton_meaning->setText(newton);
}
