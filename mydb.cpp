#include "mydb.h"

MyDB *MyDB::instance = nullptr;
MyDBDestroyer MyDB::destroyer;

MyDB::MyDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../TaMP/MY_DATABASE.db");
    if (!db.open())
        qDebug() << "openDatabaseError\r\n";
}

bool MyDB::createTable()
{
    QSqlQuery query(db);
    return query.exec("create table users(id integer primary key not null, login text not null unique, password text not null, email text not null unique);");
}

MyDB::~MyDB()
{
    db.close();
}

MyDB &MyDB::get_instance()
{
    if (!instance)
    {
        instance = new MyDB();
        if (!instance->db.tables().contains(QStringLiteral("users")))
            instance->createTable();
    }
    return *instance;
}

MyDBDestroyer::~MyDBDestroyer()
{
    delete instance;
}

void MyDBDestroyer::initialize(MyDB * link)
{
    instance = link;
}

QStringList MyDB::queryToDB(QStringList Src)
{
    QSqlQuery query(db);
    query.prepare(Src[0]);
    int i = 1;
    while (i < Src.size())
    {
        query.bindValue(Src[i], Src[i + 1]);
        i += 2;
    }

    QStringList res;
    if (Src[0].contains("SELECT"))
    {
        if (query.exec() && query.first())
        {
            res.append("found");
            return res;
        }
    }
    else
    {
        if (query.exec())
        {
            res.append("complete");
            return res;
        }
    }
    return res;
}
