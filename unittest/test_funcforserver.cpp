#include <QtTest>
#include "C:/Users/user/Documents/TaMP/functionsforserver.h"


class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();

private slots:
    void testEncrypt();
    void testDecrypt();

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

QTEST_APPLESS_MAIN(FuncForServer_Test)
#include "test_funcforserver.moc"
