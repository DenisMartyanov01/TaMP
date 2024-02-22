#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QByteArray>
#include <QDebug>
#include <QString>

QByteArray parsing(int, QString);
QByteArray auth(int, QString, QString);
QByteArray reg(QString, QString, QString);
QByteArray lookmystat(int);
QByteArray lookallstat();

#endif // FUNCTIONSFORSERVER_H
