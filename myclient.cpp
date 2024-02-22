#include "myclient.h"

//конструктор
MyClient::MyClient(QTcpSocket * _mTcpSocket, QString _login, int _id_connection)
{
    mTcpSocket = _mTcpSocket;
    login = _login;
    id_connection = _id_connection;
}

//диструктор
MyClient::~MyClient()
{

}

MyClient::is_auth()
{
    return true;
}
