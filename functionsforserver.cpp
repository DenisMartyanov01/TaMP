#include "functionsforserver.h"

bool checkValidEmail(QString Email)
{
    std::string Email2 = Email.trimmed().toUtf8().constData();
    qDebug() << Email2;
    const std::regex emailPattern(
        "(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$)");

    return std::regex_match(Email2, emailPattern);
}

int checkAuth = 0;

QByteArray parsing(QString Request)
{
    QStringList parts = Request.split("&");
    if (parts.at(0) == "auth" && parts.length() > 2)
    {
        return auth(parts.at(1), parts.at(2));
    }
    else if (parts.contains("reg") && parts.length() > 2)
    {
        return reg(parts.at(1), parts.at(2), parts.at(3));
    }
    else if (parts.contains("lookmystat") && parts.length() > 2)
    {
        return lookmystat(parts.at(1), parts.at(2));
    }
    else if (parts.contains("lookallstat") && parts.length() > 2)
    {
        return lookallstat(parts.at(1), parts.at(2));
    }
    else if (parts.at(0) == "graph" && parts.length() > 2)
    {
        bool conversionOk;
        int size = parts.at(2).toInt(&conversionOk);
        if (!conversionOk) //|| parts.size() != size*size + 2
        {
            return "Invalid graph data format";
        }
        std::vector<std::vector<int>> graph(size, std::vector<int>(size, 0));
        int dataIndex = 3;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                graph[i][j] = parts.at(dataIndex).toInt(&conversionOk);
                if (!conversionOk)
                {
                    return "Invalid graph data format";
                }
                ++dataIndex;
            }
        }
        return allShortestPaths(parts.at(1), graph);
    }
    else
    {
        return QByteArray("functionError\r\n");
    }
}

QByteArray auth(QString Login, QString Password)
{
    QStringList Src;
    Src.append("SELECT login, password FROM users WHERE login = :login and password = :password;");
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src);
    if (Src.size() > 0)
    {
        checkAuth = 1;
        return (QString("authComplete&") + Login + "\n").toUtf8();
    }
    else
        return QByteArray("authError\r\n");
}

QByteArray reg(QString Login, QString Password, QString Email)
{
    if (checkValidEmail(Email))
    {
        QStringList Src;
        Src.append("SELECT login, password FROM users WHERE login = :login and password = :password;");
        Src.append(":login");
        Src.append(Login);
        Src.append(":password");
        Src.append(Password);
        Src = MyDB::get_instance().queryToDB(Src);
        if (Src.size() > 0)
        {
            return QByteArray("accountExists\r\n");
        }
        else
        {
            Src.clear();
            Src.append("INSERT INTO users (login, password, email) VALUES (:login, :password, :email);");
            Src.append(":login");
            Src.append(Login);
            Src.append(":password");
            Src.append(Password);
            Src.append(":email");
            Src.append(Email);
            Src = MyDB::get_instance().queryToDB(Src);
            Src.clear();
            Src.append("SELECT login, password FROM users WHERE login = :login and password = :password;");
            Src.append(":login");
            Src.append(Login);
            Src.append(":password");
            Src.append(Password);
            Src = MyDB::get_instance().queryToDB(Src);
            if (Src.size() > 0)
                return (QString("regComplete&") + Login + "\n").toUtf8();
            else
                return QByteArray("regError\r\n");
        }
    }
    else
        return QByteArray("EmailWrong\r\n");
}



QByteArray lookmystat(QString Login, QString Password)
{
    QStringList Src;
    Src.append("SELECT login, password FROM users WHERE login = :login and password = :password UNION SELECT login, password FROM admins WHERE login = :login AND password = :password;"); // вывод данных как user так и admin
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src);
    if (Src.size() > 0)
    {
        QString res = "mystat&";
        while(Src.size()>0)
        {
            res.append(Src.front()).append("&");
            Src.pop_front();
        }
        return res.toUtf8();
    }
    else
        return QByteArray("mystatError\r\n");
}

QByteArray lookallstat(QString Login, QString Password)
{
    QStringList Src;
    Src.append("SELECT * FROM users WHERE EXISTS ( SELECT 1 FROM admins WHERE login = :login AND password = :password);"); //проверка на наличие прав админа
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src);
    if (Src.size() > 0)
    {
        QString res = "allstatComplete&";
        while(Src.size() > 0)
        {
            res.append(Src.front()).append("&");
            Src.pop_front();
        }
        return res.toUtf8();
    }
    else
        return QByteArray("allstatError\r\n");
}

// std::string desEncrypt(const std::string &plainText, const std::string &key)
// {
//     // Инициализация контекста шифрования
//     EVP_CIPHER_CTX *ctx;
//     ctx = EVP_CIPHER_CTX_new();
//     EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, (const unsigned char *)key.c_str(), NULL);

//     // Выделение памяти для буфера шифрования
//     int cipherTextLen = plainText.length() + AES_BLOCK_SIZE;
//     unsigned char *cipherText = new unsigned char[cipherTextLen];

//     // Шифрование
//     int len;
//     EVP_EncryptUpdate(ctx, cipherText, &len, (const unsigned char *)plainText.c_str(), plainText.length());
//     int cipherLen = len;

//     // Завершение шифрования
//     EVP_EncryptFinal_ex(ctx, cipherText + len, &len);
//     cipherLen += len;

//     std::string result((char *)cipherText, cipherLen);

//     // Очистка и освобождение ресурсов
//     delete[] cipherText;
//     EVP_CIPHER_CTX_free(ctx);

//     return result;
// }


// std::string desDecrypt(const std::string &cipherText, const std::string &key)
// {
//     // Инициализация контекста расшифрования
//     EVP_CIPHER_CTX *ctx;
//     ctx = EVP_CIPHER_CTX_new();
//     EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, (const unsigned char *)key.c_str(), NULL);

//     // Выделение памяти для буфера расшифрования
//     int plainTextLen = cipherText.length();
//     unsigned char *plainText = new unsigned char[plainTextLen];

//     // Расшифрование
//     int len;
//     EVP_DecryptUpdate(ctx, plainText, &len, (const unsigned char *)cipherText.c_str(), cipherText.length());
//     int plainLen = len;

//     // Завершение расшифрования
//     EVP_DecryptFinal_ex(ctx, plainText + len, &len);
//     plainLen += len;

//     std::string result((char *)plainText, plainLen);

//     // Очистка и освобождение ресурсов
//     delete[] plainText;
//     EVP_CIPHER_CTX_free(ctx);

//     return result;
// }



std::vector<std::vector<int>> floydWarshall(const std::vector<std::vector<int>>& graph)
{
    int V = graph.size();
    std::vector<std::vector<int>> dist(V, std::vector<int>(V, std::numeric_limits<int>::max()));

    // Инициализация расстояний между вершинами
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];

    // Обновление расстояний для каждой пары вершин через промежуточные вершины
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

QByteArray allShortestPaths(const QString& Login, const std::vector<std::vector<int>>& graph)
{
    QString task = "";

    for (const auto& innerVector : graph)
    { // Обходим векторы внутри graph
        for (int value : innerVector)
        { // Обходим значения внутри каждого вектора
            task += QString::number(value) + " "; // Добавляем значение в строку с пробелом после каждого числа
        }
    }
    // Получаем кратчайшие пути между всеми парами вершин
    std::vector<std::vector<int>> shortestPaths = floydWarshall(graph);

    // Формируем результат в формате QByteArray и отправляем клиенту
    QByteArray result;
    for (const auto& row : shortestPaths)
    {
        for (int dist : row)
        {
            result.append(QString::number(dist).toUtf8()).append(" ");
        }
        result.append("\n");
    }

    if (checkAuth == 1)
    {
        checkAuth = 0;
        QStringList taskInfo;
        taskInfo.append("UPDATE users SET task = :task, solution = :solution WHERE login = :login;");
        taskInfo.append(":task");
        taskInfo.append(task);
        taskInfo.append(":solution");
        taskInfo.append(result);
        taskInfo.append(":login");
        taskInfo.append(Login);
        // Выполняем запрос
        MyDB::get_instance().queryToDB(taskInfo);
        qDebug() << "dataSave\r\n";
    }
    return result;
}


