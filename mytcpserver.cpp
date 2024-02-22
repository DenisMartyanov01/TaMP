#include "mytcpserver.h"

MyTcpServer::~MyTcpServer() // проблема в диструторе
{
    mTcpServer->close();
    clients.clear();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
        clients.append(MyClient(mTcpSocket,"",mTcpSocket->socketDescriptor()));
   // }
}

void MyTcpServer::slotServerRead(){
    QString res = "";
    QTcpSocket* mTcpSocket = (QTcpSocket *)sender();
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        qDebug()<<array;
        if(array=="\x01")
        {
            mTcpSocket->write(res.toUtf8());
            res = "";
        }
        else
            res.append(array);
    }
    // проблема с логином, добавить set login в parsing? или вернуться к её эхо-серверу
    mTcpSocket->write(parsing(mTcpSocket->socketDescriptor(),res.toUtf8().trimmed()));

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* mTcpSocket = (QTcpSocket *)sender();

    mTcpSocket->close();
}
