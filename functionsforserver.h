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
// #include <openssl/aes.h>
// #include <openssl/evp.h>

QByteArray parsing(QString);
QByteArray auth(QString, QString);
QByteArray reg(QString, QString, QString);
QByteArray lookmystat(QString, QString);
QByteArray lookallstat(QString, QString);

// QByteArray desEncrypt(QByteArray plaintext, QByteArray);
// QByteArray desDecrypt(QByteArray ciphertext, QByteArray key);

std::vector<std::vector<int>> floydWarshall(const std::vector<std::vector<int>>&);
QByteArray allShortestPaths(const QString&, const std::vector<std::vector<int>>&);
#endif // FUNCTIONSFORSERVER_H
