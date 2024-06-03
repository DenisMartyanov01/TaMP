#include "singleton_client.h"

QString en_alph = "abcdefghijklmnopqrstuvwxyz";
QString key = "yourencryptionkey";
//QString ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

QString Encrypt(QString alphabet, QString input, QString key)
{
    input = input.toLower();
    key = key.toLower();
    QString output;
    int key_number = 0;
    int n = (alphabet.length());
    int k = -1;
    int p = -1;

    for(int i =0; i<(input.length()); i++)
    {
        if (input.at(i).isLetter())
        {

            //Поиск i-той буквы слова в алфавите
            for(int z = 0; z < n; z++)
            {
                if(alphabet.at(z) == input.at(i))
                {
                    p = z;
                    break;
                }
            }
            if (p == -1) return "Ошибка.";

            //Поиск i-той буквы ключа в алфавите
            for(int j = 0; j < n;j++)
            {
                if(alphabet.at(j) == key.at(key_number))
                {
                    if(key_number == (key.length()-1)) key_number=0;
                    else key_number++;
                    k = j;
                    break;
                }
            }
            if (k == -1) return "Ошибка.";
            //Формула: c = (p+k)%n, где p - порядковый номер i-той буквы слова в алфавите, k - порядковый номер i-той буквы ключа, n - мощность алфавита
            output.append(alphabet.at((p+k)%n));

        }
        //Знаки, которые не являются буквами, не шифруются
        else output.append(input.at(i));
    }
    return output;
}

QString Decrypt( QString alphabet, QString input, QString key)
{
    input = input.toLower();
    key = key.toLower();
    QString output;
    int key_number = 0;
    int n = (alphabet.length());
    int k = -1;
    int p = -1;

    for(int i =0; i<(input.length()); i++)
    {
        if (input.at(i).isLetter())
        {

            //Поиск i-той буквы зашифрованного слова в алфавите
            for(int z =0; z < n; z++)
            {
                if(alphabet.at(z) == input.at(i))
                {
                    p = z;
                    break;
                }
            }
            if (p == -1) return "Ошибка.";

            //Поиск i-той буквы ключа в алфавите
            for(int j = 0; j < n;j++)
            {
                if(alphabet.at(j) == key.at(key_number))
                {
                    if(key_number == (key.length()-1)) key_number=0;
                    else key_number++;
                    k =j;
                    break;
                }
            }
            if (k == -1) return "Ошибка.";
            //Формула: c = (p-k+n)%n, где p - порядковый номер i-той буквы слова в алфавите, k - порядковый номер i-той буквы ключа, n - мощность алфавита
            output.append(alphabet.at((p-k+n)%n));
        }
        //Знаки, которые не являются буквами, не шифруются
        else output.append(input.at(i));
    }
    return output;
}

Singleton_destroyer::~Singleton_destroyer()
{
    delete p_instance;
}

void Singleton_destroyer::initialize(Singleton_client* p)
{
    p_instance = p;
}

Singleton_client::Singleton_client(QObject* parent) : QObject(parent)
{
    mTcpSocket = new QTcpSocket(this);
    qDebug() << "connecting to server\n";
    mTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &Singleton_client::slot_server_read);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &Singleton_client::slot_client_disconnect);
}

Singleton_client::~Singleton_client()
{
    mTcpSocket->close();
}

Singleton_client* Singleton_client::get_instance()
{
    if (!p_instance) {
        p_instance = new Singleton_client();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void Singleton_client::send_msg_to_server(QString query)
{
    qDebug() << "sending request to server\n";
    mTcpSocket->write(Encrypt(en_alph, query, key).toUtf8());
}

void Singleton_client::slot_server_read()
{
    QString msg = "";
    while (mTcpSocket->bytesAvailable() > 0) {
        QByteArray array = mTcpSocket->readAll();
        msg.append(array);
    }
    qDebug() << "reading server message\n";
    qDebug() << msg;
    emit msg_from_server(Decrypt(en_alph, msg, key));
}

void Singleton_client::slot_client_disconnect()
{
    mTcpSocket->deleteLater();
    qDebug() << "disconnected from server\n";
}

Singleton_client* Singleton_client::p_instance = nullptr;
Singleton_destroyer Singleton_client::destroyer;
