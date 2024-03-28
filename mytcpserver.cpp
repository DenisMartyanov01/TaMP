#include "mytcpserver.h"
#include "functionsforserver.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    }
    else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    QTcpSocket *current_socket;
    current_socket = mTcpServer->nextPendingConnection();
    connect(current_socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(current_socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    mTcpSocket.insert(current_socket->socketDescriptor(), current_socket);
}

void MyTcpServer::slotServerRead(){
    QString res = "";
    QTcpSocket *current_socket = mTcpSocket[((QTcpSocket *)sender())->socketDescriptor()];
    while (current_socket->bytesAvailable() > 0)
    {
        QByteArray array = current_socket->readAll();
        res.append(array);
    }
    current_socket->write(parsing(res));
}

void MyTcpServer::slotClientDisconnected(){
    int key = QTcpSocket(sender()).socketDescriptor();
    mTcpSocket[key]->close();
    mTcpSocket.remove(key);
}
