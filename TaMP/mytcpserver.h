#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QCoreApplication>
#include <QByteArray>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QMap>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    int numClients;
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    QMap<int, QTcpSocket*> mTcpSocket;
};
#endif // MYTCPSERVER_H
