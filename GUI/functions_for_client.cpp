#include "functions_for_client.h"

functions_for_client::functions_for_client()
{
    ui_auth = new auth_reg;
    ui_auth->show();
    connect(ui_auth, &auth_reg::is_auth, this, &functions_for_client::is_auth);
    connect(ui_auth, &auth_reg::on_reg, this, &functions_for_client::on_reg);
}

void functions_for_client::is_auth(QString login, QString password)
{
    QString prompt = "auth&" + login + "&" + password + "&";
    Singleton_client::get_instance();
    Singleton_client::get_instance()->send_msg_to_server(prompt);

    if (this->ui_auth->isVisible())
    // temporary
    if(login == "user" && password == "123"){
        ui_main = new MainWindow;
        ui_main->show();
        delete ui_auth;
    }
}

void functions_for_client::on_reg(QString login, QString password, QString email)
{
    QString prompt = "reg&" + login + "&" + password + "&" + email + "&";
    Singleton_client::get_instance();
    Singleton_client::get_instance()->send_msg_to_server(prompt);

    // if(everything ok)
    ui_main = new MainWindow;
    ui_main->show();
    delete ui_auth;
}
