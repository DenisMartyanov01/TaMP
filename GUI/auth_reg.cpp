#include "ui_auth_reg.h"
#include "auth_reg.h"
#include "sha1.hpp"

QString hash(QString input)
{
    SHA1 checksum;
    checksum.update(input.toStdString());
    QString h = QString::fromStdString(checksum.final());
    return h;
}

auth_reg::auth_reg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::auth_reg)
{
    ui->setupUi(this);
    ui->label_email->setVisible(false);
    ui->lineEdit_email->setVisible(false);
    ui->pushButton_reg->setVisible(false);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

auth_reg::~auth_reg()
{
    delete ui;
}

void auth_reg::on_pushButton_login_clicked()
{
    emit is_auth(ui->lineEdit_login->text(), hash(ui->lineEdit_password->text())); // hash
    //emit is_auth(ui->lineEdit_login->text(), ui->lineEdit_password->text()); // without hash
}

void auth_reg::on_pushButton_change_clicked()
{
    bool flag = ui->pushButton_login->isVisible();
    if (flag) {
        ui->pushButton_change->setText("Sign in");
    }
    else {
        ui->pushButton_change->setText("Sign up");
    }
    ui->pushButton_login->setVisible(!flag);
    ui->pushButton_reg->setVisible(flag);
    ui->label_email->setVisible(flag);
    ui->lineEdit_email->setVisible(flag);
}

void auth_reg::on_pushButton_exit_clicked()
{
    this->close();
}


void auth_reg::on_pushButton_reg_clicked()
{
    emit on_reg(ui->lineEdit_login->text(), hash(ui->lineEdit_password->text()), ui->lineEdit_email->text()); // hash
    //emit on_reg(ui->lineEdit_login->text(), ui->lineEdit_password->text(), ui->lineEdit_email->text()); // without hash
}

void auth_reg::on_error(QString line)
{
    this->ui->label_error->setText(line);
}
