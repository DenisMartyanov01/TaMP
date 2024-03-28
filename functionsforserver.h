#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QByteArray>
#include <QString>
#include <QStringList>

#include "mydb.h"
#include <regex>

QByteArray parsing(QString);
QByteArray auth(QString, QString);
QByteArray reg(QString, QString, QString);
QByteArray lookmystat(QString, QString);
QByteArray lookallstat(QString, QString);

#endif // FUNCTIONSFORSERVER_H
