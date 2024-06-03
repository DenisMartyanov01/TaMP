#include "functions_for_client.h"
#include <QStringList>


functions_for_client::functions_for_client()
{
    ui_auth = new auth_reg;
    ui_auth->show();
    connect(ui_auth, &auth_reg::is_auth, this, &functions_for_client::is_auth);
    connect(ui_auth, &auth_reg::on_reg, this, &functions_for_client::on_reg);
    connect(Singleton_client::get_instance(), &Singleton_client::msg_from_server, this, &functions_for_client::msg_resolve);
    connect(this, &functions_for_client::on_final_auth, this, &functions_for_client::final_auth);  // Correct signal connection
}

void functions_for_client::is_auth(QString login, QString password)
{
    QString prompt = "auth&" + login + "&" + password + "&";
    this->login = login;
    this->password = password;
    Singleton_client::get_instance()->send_msg_to_server(prompt);
}

void functions_for_client::final_auth()
{
    ui_main = new MainWindow;
    connect(ui_main, &MainWindow::send_task, this, &functions_for_client::task_send);
    connect(ui_main, &MainWindow::request_lookmystat_main, this, &functions_for_client::on_request_lookmystat_func);
    connect(ui_main, &MainWindow::request_lookallstat_main, this, &functions_for_client::on_request_lookallstat_func);
    connect(ui_main, &MainWindow::request_sort_main, this, &functions_for_client::on_request_sort_func);

    ui_main->show();
    delete ui_auth;
}

void functions_for_client::on_reg(QString login, QString password, QString email)
{
    QString prompt = "reg&" + login + "&" + password + "&" + email + "&";
    Singleton_client::get_instance()->send_msg_to_server(prompt);
    this->login = login;
    this->password = password;
    ui_main = new MainWindow;
    ui_main->show();
    connect(ui_main, &MainWindow::send_task, this, &functions_for_client::task_send);
    delete ui_auth;
}

void functions_for_client::task_send(int i, QString text)
{
    QString prompt;
    switch (i) {
    case 1:
        prompt = "newton&" + this->login + "&" + text + "&";
        break;
    case 2:
        prompt = "music&" + this->login + "&" + text + "&";
        break;
    case 3:
        prompt = "graph&" + this->login + "&" + text + "&";
        break;
    default:
        break;
    }
    Singleton_client::get_instance()->send_msg_to_server(prompt);
}

void functions_for_client::msg_resolve(QString msg)
{
    QStringList msgParts = msg.split('&');
    if (msgParts[0] == "reg" || msgParts[0] == "auth") {
        emit on_final_auth(msgParts[1]); // Correct emission of the signal
    }
}

void functions_for_client::on_request_lookmystat_func()
{
    QString prompt = "lookmystat&" + this->login + "&" + this->password + "&";
    Singleton_client::get_instance()->send_msg_to_server(prompt);
}

void functions_for_client::on_request_lookallstat_func()
{
    QString prompt = "lookallstat&" + this->login + "&" + this->password + "&";
    Singleton_client::get_instance()->send_msg_to_server(prompt);
}

void functions_for_client::on_request_sort_func(QString sorti)
{
    QString prompt = "sortallstat&" + this->login + "&" + this->password + "&";
    if (sorti == "graph"){
        prompt += sorti + "&";
    }
    else if (sorti == "newton"){
        prompt += sorti + "&";
    }
    else if (sorti == "music"){
        prompt += sorti + "&";
    }

    Singleton_client::get_instance()->send_msg_to_server(prompt);
}
