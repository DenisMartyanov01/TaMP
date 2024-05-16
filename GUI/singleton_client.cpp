#include "singleton_client.h"

Singleton_destroyer::~Singleton_destroyer()
{
    delete p_instance;
}

void Singleton_destroyer::initialize(Singleton_client* p)
{
    p_instance = p;
}

Singleton_client::Singleton_client(QObject* parent) : QObject(parent)
{
    mTcpSocket = new QTcpSocket(this);
    qDebug() << "connecting to server\n";
    mTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(mTcpSocket, SIGNAL(readyRead()), this, SLOT(slot_server_read()));
    connect(mTcpSocket, SIGNAL(disconnected()), this, SLOT(slot_client_disconnect()));
}

Singleton_client::~Singleton_client()
{
    mTcpSocket->close();
}

Singleton_client* Singleton_client::get_instance()
{
    if (!p_instance){
        p_instance = new Singleton_client();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void Singleton_client::send_msg_to_server(QString query)
{
    qDebug() << "sending request to server\n";
    mTcpSocket->write(query.toUtf8());
}

void Singleton_client::slot_server_read()
{
    QString msg = "";
    while(mTcpSocket->bytesAvailable() > 0){
        QByteArray array = mTcpSocket->readAll();
        msg.append(array);
    }
    qDebug() << "reading server message\n";
    qDebug() << msg;
    emit msg_from_server(msg);
}

void Singleton_client::slot_client_disconnect()
{
    mTcpSocket->deleteLater();
    qDebug() << "disconnected from server\n";
}

Singleton_client* Singleton_client::p_instance;
Singleton_destroyer Singleton_client::destroyer;
