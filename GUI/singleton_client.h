#ifndef SINGLETON_CLIENT_H
#define SINGLETON_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

// Forward declaration of Singleton_destroyer to break circular dependency
class Singleton_destroyer;

class Singleton_client : public QObject
{
    Q_OBJECT

public:
    static Singleton_client* get_instance();
    ~Singleton_client();
    void send_msg_to_server(QString query);

signals:
    void msg_from_server(QString msg);

private slots:
    void slot_server_read();
    void slot_client_disconnect();

private:
    Singleton_client(QObject* parent = nullptr);
    static Singleton_client* p_instance;
    static Singleton_destroyer destroyer;
    QTcpSocket* mTcpSocket;

    friend class Singleton_destroyer;
};

class Singleton_destroyer
{
public:
    ~Singleton_destroyer();
    void initialize(Singleton_client* p);

private:
    Singleton_client* p_instance = nullptr;
};

#endif // SINGLETON_CLIENT_H
