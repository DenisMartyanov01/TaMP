#include "functionsforserver.h"

//id_connection - id_admin/id_user != 1/0 = 123..153
QByteArray parsing(int id_connection, QString Request)
{
    //qDebug()<<Request;
    QStringList parts = Request.split("&");
    //QString Login = "user", Password = "qwer", Gmail = "asdf";
    if (parts.at(0) == "authorization" && parts.length() > 2)
    {
        return auth(id_connection, parts.at(1), parts.at(2));
    }
    else if (parts.contains("registration") && parts.length() > 2)
    {
        return reg(parts.at(0), parts.at(1), parts.at(2));
    }
    else
    {
        return QByteArray("error\r\n");
    }
}

QByteArray auth(int id_connection, QString Login, QString Password)
{
        return QByteArray("auth\r\n");
}

QByteArray reg(QString Login, QString Password, QString Gmail)
{
        return QByteArray("reg\r\n");
}

QByteArray lookmystat(int id_connection)
{
        return QByteArray("mystat\r\n");
}

QByteArray lookallstat()
{
        return QByteArray("allstat\r\n");
}


