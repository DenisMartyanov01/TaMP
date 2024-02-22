#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QString>

class MyClient
{
public:
    MyClient(QTcpSocket *, QString, int);
    ~MyClient();
    bool is_auth();
    //...
private:
    QTcpSocket * mTcpSocket;
    QString login;
    int id_connection;
};

#endif // MYCLIENT_H
