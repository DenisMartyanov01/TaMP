#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H

#include <QObject>
#include "mainwindow.h"
#include "auth_reg.h"
#include "singleton_client.h"

class functions_for_client : public QObject
{
    Q_OBJECT

public:
    functions_for_client();

signals:
    void on_auth_ok();
    void on_error_login(QString);
    void on_error_stat(QString);
    void received_mystat(int, int, int);
    void received_allstat(QString, QString, QString, QString);

public slots:
    void is_auth(QString login, QString password);
    void on_reg(QString login, QString password, QString email);
    void task_send(int i, QString text);
    void msg_resolve(QString msg);
    void on_request_lookmystat_func();
    void on_request_lookallstat_func();
    void on_request_sort_func(QString);

private:
    MainWindow* ui_main;
    auth_reg* ui_auth;
    QString login;
    QString password;
};

#endif // FUNCTIONS_FOR_CLIENT_H
