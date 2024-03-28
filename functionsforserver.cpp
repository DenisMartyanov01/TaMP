#include "functionsforserver.h"

bool checkValidEmail(QString Email)
{
    std::string Email2 = Email.trimmed().toUtf8().constData();
    qDebug() << Email2;
    const std::regex emailPattern(
        "(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$)");

    return std::regex_match(Email2, emailPattern);
}

QByteArray parsing(QString Request)
{
    QStringList parts = Request.split("&");
    if (parts.at(0) == "auth" && parts.length() > 2)
    {
        return auth(parts.at(1), parts.at(2));
    }
    else if (parts.contains("regist") && parts.length() > 2)
    {
        return reg(parts.at(1), parts.at(2), parts.at(3));
    }
    else if (parts.contains("lookmystat") && parts.length() > 2)
    {
        return lookmystat(parts.at(1), parts.at(2));
    }
    else if (parts.contains("lookallstat") && parts.length() > 2)
    {
        return lookallstat(parts.at(1), parts.at(2));
    }
    else
    {
        return QByteArray("functionError\r\n");
    }
}

QByteArray auth(QString Login, QString Password)
{
    QStringList Src;
    Src.append("SELECT login, password FROM users WHERE login = :login and password = :password;");
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src);
    if (Src.size() > 0)
        return (QString("authComplete&") + Login + "\n").toUtf8();
    else
        return QByteArray("authError\r\n");
}

QByteArray reg(QString Login, QString Password, QString Email)
{
    if (checkValidEmail(Email))
    {
        QStringList Src;
        Src.append("SELECT login, password FROM users WHERE login = :login and password = :password;");
        Src.append(":login");
        Src.append(Login);
        Src.append(":password");
        Src.append(Password);
        Src = MyDB::get_instance().queryToDB(Src); //проверка на наличие в бд
        if (Src.size() > 0)
        {
            return QByteArray("accountExists\r\n");
        }
        else
        {
            Src.append("INSERT INTO users (login, password, email) VALUES (:login, :password, :email);");
            Src.append(":login");
            Src.append(Login);
            Src.append(":password");
            Src.append(Password);
            Src.append(":email");
            Src.append(Email);
            Src = MyDB::get_instance().queryToDB(Src);
            if (Src.size() > 0)
                return (QString("regComplete&") + Login + "\n").toUtf8();
            else
                return QByteArray("regError\r\n");
        }
    }
    else
        return QByteArray("EmailWrong\r\n");
}



QByteArray lookmystat(QString Login, QString Password)
{
    QStringList Src;
    Src.append("SELECT login, password FROM users WHERE login = :login and password = :password;");
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src); //проверка на наличие в бд
    if (Src.size() > 0)
        return QByteArray("mystatComplete\r\n");
    else
        return QByteArray("mystatError\r\n");
}

QByteArray lookallstat(QString Login, QString Password)
{
    QStringList Src;
    Src.append("SELECT * FROM users IF admins.login = :login and admins.password = :password;"); //проверка на наличие прав
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src); //проверка на наличие в бд
    if (Src.size() > 0)
        return QByteArray("allstatComplete\r\n");
    else
        return QByteArray("allstatError\r\n");
}
