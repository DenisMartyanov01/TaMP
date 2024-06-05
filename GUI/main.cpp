#include "functions_for_client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    functions_for_client func;
    return a.exec();
}
