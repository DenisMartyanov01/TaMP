#include <QtTest>
#include "C:/TaMP/functionsforserver.h"


class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();

private slots:
    void testEncrypt();
    void testDecrypt();
    void testGraph();
};

FuncForServer_Test::FuncForServer_Test()
{

}

FuncForServer_Test::~FuncForServer_Test()
{

}

void FuncForServer_Test::testEncrypt()
{

   QString en_alph = "abcdefghijklmnopqrstuvwxyz";
    QString input = "hello";
    QString key = "key";
    QString encrypted = Encrypt(en_alph, input, key);

    QCOMPARE(encrypted, QString("rijvs"));
}

void FuncForServer_Test::testDecrypt()
{

    QString en_alph = "abcdefghijklmnopqrstuvwxyz";
    QString input = "rijvs";
    QString key = "key";
    QString decrypted = Decrypt(en_alph, input, key);

    QCOMPARE(decrypted, QString("hello"));
}

void FuncForServer_Test::testGraph()
{
    std::vector<std::vector<int>> graph = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    std::vector<std::vector<int>> expectedDist = {
        {0, 5, 8, 9},
        {INT_MAX, 0, 3, 4},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    std::vector<std::vector<int>> resultDist = floydWarshall(graph);

    QCOMPARE(expectedDist, resultDist);
}

QTEST_APPLESS_MAIN(FuncForServer_Test)
#include "test_funcforserver.moc"
