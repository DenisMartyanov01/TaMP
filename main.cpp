#include <QCoreApplication>
#include "mytcpserver.h"
#include "functionsforserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
