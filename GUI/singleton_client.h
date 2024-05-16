// #ifndef SINGLETON_CLIENT_H
// #define SINGLETON_CLIENT_H

// #endif // SINGLETON_CLIENT_H

// #ifndef SINGLETON_CLIENT_H
// #endif // SINGLETON_CLIENT_H


#ifndef SINGLETON_CLIENT_H
#define SINGLETON_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QString>

class Singleton_client;

class Singleton_destroyer
{
private:
    Singleton_client* p_instance;
public:
    ~Singleton_destroyer();
    void initialize(Singleton_client*);
};

class Singleton_client:QObject
{
    Q_OBJECT
private:
    static Singleton_client* p_instance;
    static Singleton_destroyer destroyer;
    QTcpSocket* mTcpSocket;
protected:
    explicit Singleton_client(QObject* parent = nullptr);
    Singleton_client(Singleton_client&) = delete;
    Singleton_client& operator= (Singleton_client&) = delete;
    ~Singleton_client();
    friend class Singleton_destroyer;

public:
    static Singleton_client* get_instance();
    void send_msg_to_server(QString query);

signals:
    void msg_from_server(QString msg);

private slots:
    void slot_server_read();
    void slot_client_disconnect();

};

#endif // SINGLETON_CLIENT_H
