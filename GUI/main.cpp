#include "functions_for_client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    functions_for_client func;
    return a.exec();
}
