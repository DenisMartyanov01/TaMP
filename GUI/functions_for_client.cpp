#include "functions_for_client.h"
#include <QStringList>


functions_for_client::functions_for_client()
{
    ui_auth = new auth_reg;
    ui_auth->show();
    connect(ui_auth, &auth_reg::is_auth, this, &functions_for_client::is_auth);
    connect(ui_auth, &auth_reg::on_reg, this, &functions_for_client::on_reg);
    connect(Singleton_client::get_instance(), &Singleton_client::msg_from_server, this, &functions_for_client::msg_resolve);
    connect(this, &functions_for_client::on_error_login, ui_auth, &auth_reg::on_error);
}

void functions_for_client::is_auth(QString login, QString password)
{
    QString prompt = "auth&" + login + "&" + password + "&";
    this->login = login;
    this->password = password;
    Singleton_client::get_instance()->send_msg_to_server(prompt);
}

void functions_for_client::on_reg(QString login, QString password, QString email)
{
    QString prompt = "reg&" + login + "&" + password + "&" + email + "&";
    Singleton_client::get_instance()->send_msg_to_server(prompt);
    this->login = login;
    this->password = password;
    Singleton_client::get_instance()->send_msg_to_server(prompt);
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
    QList msg_parts = msg.split('&');
    QList msg_parts2 = msg.split('%');
    if (msg_parts[0] == "user" || msg_parts[0] == "admin" || msg_parts[0] == "regcomplete") {
        ui_main = new MainWindow;
        connect(ui_main, &MainWindow::send_task, this, &functions_for_client::task_send);
        connect(ui_main, &MainWindow::request_lookmystat_main, this, &functions_for_client::on_request_lookmystat_func);
        connect(ui_main, &MainWindow::request_lookallstat_main, this, &functions_for_client::on_request_lookallstat_func);
        connect(ui_main, &MainWindow::request_sort_main, this, &functions_for_client::on_request_sort_func);
        connect(this, &functions_for_client::received_mystat, ui_main, &MainWindow::slot_received_mystat);
        connect(this, &functions_for_client::received_allstat, ui_main, &MainWindow::slot_received_allstat);

        ui_main->show();
        delete ui_auth;
    }
    else if(msg == "autherror\r\n" || msg == "regerror\r\n"){
        emit on_error_login("error");
    }
    else if(msg == "accountexists\r\n"){
        emit on_error_login("account exists");
    }
    else if(msg == "emailwrong\r\n"){
        emit on_error_login("wrong email");
    }
    else if(msg_parts[0] == "mystat"){
        emit received_mystat(msg_parts2[1].toInt(), msg_parts2[2].toInt(), msg_parts2[3].toInt());
    }
    else if(msg == "mystatError\r\n" || msg == "allstatError&" || msg == "sortallstatError&"){
        emit on_error_stat("error");
    }
    else if(msg_parts2[0][0] >= '0' && msg_parts2[0][0] <= '9'){
        QString logins = "";
        QString graph = "";
        QString music = "";
        QString newton = "";
        QList temp = msg_parts[0].split('%');
        for(int i = 0; i < msg_parts.size(); ++i){
            temp = msg_parts[i].split('%');
            if (temp.size() > 5) {
                logins += temp[1] + " ";
                graph += temp[3] + " ";
                music += temp[4] + " ";
                newton += temp[5] + " ";
            }
        }
        emit received_allstat(logins, graph, music, newton);
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
