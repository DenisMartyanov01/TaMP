#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QByteArray>
#include <QString>
#include <QStringList>

#include <vector>
#include <limits>
#include "mydb.h"
#include <regex>
#include <string>


QByteArray parsing(QString);
QByteArray auth(QString, QString);
QByteArray reg(QString, QString, QString);
QByteArray lookmystat(QString, QString);
QByteArray lookallstat(QString, QString);
QString Encrypt(QString, QString, QString);
QString Decrypt(QString, QString, QString);

void decreaseGraphCount(const QString&);

std::vector<std::vector<int>> floydWarshall(const std::vector<std::vector<int>>&);
QByteArray allShortestPaths(const QString&, const std::vector<std::vector<int>>&);
#endif // FUNCTIONSFORSERVER_H
