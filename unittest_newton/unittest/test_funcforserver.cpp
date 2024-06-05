#include <QtTest>
#include "C:/QT_projects/TaMP/functionsforserver.h"


class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();

private slots:
    void testNewton1();
    void testNewton2();
    void testNewton3();
    void testNewton4();
    void testNewton5();
};

FuncForServer_Test::FuncForServer_Test()
{

}

FuncForServer_Test::~FuncForServer_Test()
{

}

void FuncForServer_Test::testNewton1()
{
    QCOMPARE_LE(fabs(newton(1, 2, 1, -10, 10) - (-1)), 1.0);
}

void FuncForServer_Test::testNewton2()
{
    QCOMPARE_LE(fabs(newton(1, -3, 2, 0, 3) - 1.0), 1.0);
}

void FuncForServer_Test::testNewton3()
{
    QCOMPARE_LE(fabs(newton(2, -5, 4, -10, 3) - 1.0), 1.0);
}

void FuncForServer_Test::testNewton4()
{
    QCOMPARE_LE(fabs(newton(1, -3, 2, -10, 3) - 1.0), 1.0);
}

void FuncForServer_Test::testNewton5()
{
    QCOMPARE_LE(fabs(newton(1, -3, 2, 1.5, 3) - 2.0), 1.0);
}



QTEST_APPLESS_MAIN(FuncForServer_Test)
#include "test_funcforserver.moc"
