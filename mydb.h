#ifndef MYDB_H
#define MYDB_H

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QStringList>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QtSql>

class MyDB;

class MyDBDestroyer
{
private:
    MyDB *instance;
public:
    ~MyDBDestroyer();
    void initialize(MyDB *link);
};

class MyDB
{
private:
    static MyDB *instance;
    static MyDBDestroyer destroyer;
    QSqlDatabase db;
    MyDB();
    ~MyDB();
    MyDB(const MyDB &) = delete;
    void operator = (const MyDB &) = delete;
    friend class MyDBDestroyer;
public:
    bool createTable();
    static MyDB& get_instance();
    QStringList queryToDB(QStringList src);
};


#endif // MYDB_H
