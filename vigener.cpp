#include <QDebug>
#include <QString>

QString en_alph = "abcdefghijklmnopqrstuvwxyz";
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

int main()
{
    QString inp = "London is the capital of Great Britain!London is the capital of Great Britain!London is the capital of Great Britain!";
    QString key = "limeqwerty";
    QString out;

    out = Encrypt(en_alph, inp, key);
    qDebug() << out << '\n';

    QString dout = Decrypt(en_alph, out, key);
    qDebug() << dout << '\n';

}
