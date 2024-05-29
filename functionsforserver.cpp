#include "functionsforserver.h"

bool checkValidEmail(QString Email)
{
    std::string Email2 = Email.trimmed().toUtf8().constData();
    qDebug() << Email2;
    const std::regex emailPattern(
        "(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$)");

    return std::regex_match(Email2, emailPattern);
}

void decreaseGraphCount(const QString& login)
{
    QStringList query;
    query.append("UPDATE users SET graph = graph - 1 WHERE login = :login;");
    query.append(":login");
    query.append(login);
    MyDB::get_instance().queryToDB(query);
}

int checkAuth = 0;
QString AuthAnswer = "";

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
    else if (parts.contains("sortallstat") && parts.length() > 2)
    {
        return sortallstat(parts.at(1), parts.at(2), parts.at(3));
    }
    else if (parts.at(0) == "graph" && parts.length() > 2)
    {
        bool conversionOk;
        int size = parts.at(2).toInt(&conversionOk);
        if (!conversionOk || parts.size() != size*size + 3)
        {
            decreaseGraphCount(parts.at(1));
            qDebug() << "Invalid graph data format\n";
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
    Src.append("SELECT login, password FROM users WHERE login = :login and password = :password UNION SELECT login, password FROM admins WHERE login = :login AND password = :password;");
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src);
    if (Src.size() > 0)
    {
        checkAuth = 1;
        AuthAnswer = Login;
        if (Src.at(0).contains("admin"))
        {
            qDebug() << "user\n";
            return (QString("admin&\n")).toUtf8();
        }
        else
        {
            qDebug() << "user\n";
            return (QString("user&\n")).toUtf8();
        }
    }
    else
    {
        qDebug() << "error\n";
        return QByteArray("authError\r\n");
    }
}

QByteArray reg(QString Login, QString Password, QString Email)
{
    if (checkValidEmail(Email))
    {
        QStringList Src;
        Src.append("SELECT login FROM users WHERE login = :login UNION SELECT login FROM admins WHERE login = :login;");
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
    Src.append("SELECT login, graph, music, newton FROM users WHERE login = :login and password = :password UNION SELECT login, 0 AS graph, 0 AS music, 0 AS newton FROM admins WHERE login = :login AND password = :password;"); // вывод данных как user так и admin
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
    Src.append("SELECT id, login, email, graph, music, newton FROM users WHERE EXISTS ( SELECT 1 FROM admins WHERE login = :login AND password = :password);"); //проверка на наличие прав админа
    Src.append(":login");
    Src.append(Login);
    Src.append(":password");
    Src.append(Password);
    Src = MyDB::get_instance().queryToDB(Src);

    if (Src.size() > 0)
    {
        QString res;
        while(Src.size() > 0)
        {
            res.append(Src.front()).append("&");
            Src.pop_front();
        }

        return res.toUtf8();
    }
    else
    {
        return QByteArray("allstatError&");
    }
}

QByteArray sortallstat(QString Login, QString Password, QString Columnname)
{
    QStringList Sortsrc;
    Sortsrc.append("SELECT id, login, email, graph, music, newton FROM users WHERE EXISTS (SELECT 1 FROM admins WHERE login = :login AND password = :password) ORDER BY " + Columnname + " DESC;");
    Sortsrc.append(":login");
    Sortsrc.append(Login);
    Sortsrc.append(":password");
    Sortsrc.append(Password);
    Sortsrc = MyDB::get_instance().queryToDB(Sortsrc);

    if(Sortsrc.size() > 0)
    {
        QString sortres;
        while(Sortsrc.size() > 0)
        {
            sortres.append(Sortsrc.front()).append("&");
            Sortsrc.pop_front();
        }
        return sortres.toUtf8();
    }
    else
    {
        return QByteArray("sortallstatError&");
    }
}


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
        result.append("\r\n");
    }

    qDebug() << result;

    if (checkAuth == 1 && AuthAnswer == Login)
    {
        checkAuth = 0;
        AuthAnswer.clear();
        QStringList taskInfo; // в базу данных в task добавлять или убавлять 1, вести его как счетчик
        taskInfo.append("UPDATE users SET graph = graph + 1 WHERE login = :login;");
        taskInfo.append(":login");
        taskInfo.append(Login);
        // Выполняем запрос
        MyDB::get_instance().queryToDB(taskInfo);
        qDebug() << "dataSave\r\n";
    }
    return result;
}
