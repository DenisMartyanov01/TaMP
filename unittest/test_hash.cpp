#include <QtTest>
#include "sha1.hpp"


class Hash_Test : public QObject
{
    Q_OBJECT

public:
    Hash_Test();
    ~Hash_Test();

private slots:
    void makehash();

};

Hash_Test::Hash_Test() { }

Hash_Test::~Hash_Test() { }

void Hash_Test::makehash()
{

    std::string line = "hello";

    SHA1 checksum;
    checksum.update(line);
    const std::string hash = checksum.final();

    QCOMPARE(hash, (std::string)"aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d");

}



QTEST_APPLESS_MAIN(Hash_Test)
#include "test_hash.moc"
