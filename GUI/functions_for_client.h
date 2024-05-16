#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H

#include <QObject>
#include "mainwindow.h"
#include "auth_reg.h"
#include"singleton_client.h"

class functions_for_client: public QObject
{
public:
    functions_for_client();

signals:
    void on_auth_ok();
public slots:
    void is_auth(QString, QString);
    void on_reg(QString, QString, QString);
private:
    MainWindow* ui_main;
    auth_reg* ui_auth;
};

#endif // FUNCTIONS_FOR_CLIENT_H
