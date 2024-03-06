#include "ui_auth_reg.h"
#include "auth_reg.h"

auth_reg::auth_reg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::auth_reg)
{
    ui->setupUi(this);
    ui->label_email->setVisible(false);
    ui->lineEdit_email->setVisible(false);
    ui->pushButton_reg->setVisible(false);
}

auth_reg::~auth_reg()
{
    delete ui;
}

void auth_reg::on_pushButton_Exit_clicked()
{
    this->close();
}

void auth_reg::on_pushButton_login_clicked()
{

    emit is_auth(ui->lineEdit_login->text(), ui->lineEdit_password->text());
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
/*
functions_for_client* auth_reg::get_func()
{
    return (this->func);
}
*/
