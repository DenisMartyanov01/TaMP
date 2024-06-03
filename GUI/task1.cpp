#include "task1.h"
#include "ui_task1.h"

Task1::Task1(QWidget *parent) : QWidget(parent), ui(new Ui::Task1)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
}

Task1::~Task1()
{
    delete ui;
}

void Task1::on_task1_return_clicked()
{
    emit on_return();
    this->close();
}

void Task1::set_task(int i)
{
    switch(i){
    case 1:
        this->ui->label_Task2->hide();
        this->ui->lineEdit_Task2->hide();
        this->ui->lineEdit2_Task2->hide();
        this->ui->label_Task3->hide();
        this->ui->lineEdit_Task3->hide();
        this->ui->lineEdit2_Task3->hide();
        break;
    case 2:
        this->ui->label_Task1->hide();
        this->ui->lineEdit_Task1->hide();
        this->ui->lineEdit2_Task1->hide();
        this->ui->lineEdit3_Task1->hide();
        this->ui->label_Task3->hide();
        this->ui->lineEdit_Task3->hide();
        this->ui->lineEdit2_Task3->hide();
        break;
    case 3:
        this->ui->label_Task1->hide();
        this->ui->lineEdit_Task1->hide();
        this->ui->lineEdit2_Task1->hide();
        this->ui->lineEdit3_Task1->hide();
        this->ui->label_Task2->hide();
        this->ui->lineEdit_Task2->hide();
        this->ui->lineEdit2_Task2->hide();
        break;
    default:
        break;
    }
}

QString Task1::getmsg(QString audioFilepath)
{

    QFile audioFile(audioFilepath);
    audioFile.open(QIODevice::ReadOnly);


    QByteArray data = audioFile.readAll();

    QString result;
    int size = data[100];

    for(int i = 0; i < size; i++) {

        QString letter(data[(i + 1) * 5 + 100]);
        result += letter;
    }

    return result;
}

void Task1::setmsg(QString audioFilePath, QString textFilePath)
{
    QFile audioFile(audioFilePath);
    QFile textFile(textFilePath);

    audioFile.open(QIODevice::ReadOnly);
    textFile.open(QIODevice::ReadOnly);

    QByteArray audioData;
    QByteArray textData;

    audioData = audioFile.readAll();
    textData = textFile.readAll();

    audioFile.close();
    textFile.close();

    if (audioData.size() < textData.size() * 6 + 100 ) {
        qDebug() << "too small sound file for this text";
    }

    else {

        audioFile.open(QIODevice::WriteOnly);

        audioData[100] = textData.length();

        for(int i = 0; i < textData.size(); i++) {
            audioData[(i + 1) * 5 + 100] = textData[i];
        }

        audioFile.write(audioData);
        audioFile.close();
        qDebug() << "message set into sound file";
    }
}

std::vector<std::vector<int>> floydWarshall(const std::vector<std::vector<int>>& graph)
{
    qDebug() << "floydWarshall start";
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
    qDebug() << "floydWarshall end";
    return dist;
}

std::vector<std::vector<int>> allShortestPaths(const std::vector<std::vector<int>>& graph)
{
    qDebug() << "allShortestPaths start";
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
    /*
    // Формируем результат в формате QByteArray
    QByteArray result;
    for (const auto& row : shortestPaths)
    {
        for (int dist : row)
        {
            result.append(QString::number(dist).toUtf8()).append(" ");
        }
        result.append("\r\n");
    }
    return result;
    */
    qDebug() << "allShortestPaths end";
    return shortestPaths;
}

std::vector<std::vector<int>> qstring_to_arr(QString str)
{
    qDebug() << "qstring_to_arr start";
    QTextStream stream(&str);
    std::vector<std::vector<int>> array;
    std::vector<int> temp_array;
    bool isFirst = true;
    int length, number, counter = 0;
    while (!stream.atEnd()) {
        stream >> number;
        if (isFirst){
            length = number;
            isFirst = false;
        }
        else {
            temp_array.push_back(number);
            counter++;
        }
        if (counter + 1 >= length){
            counter = 0;
            array.push_back(temp_array);
            temp_array.clear();
        }
    }
    std::vector<std::vector<int>> arr;
    arr = allShortestPaths(array);
    qDebug() << "qstring_to_arr end";
    return arr;
}

QString arr_to_qstring(std::vector<std::vector<int>> arr, int length)
{
    qDebug() << "arr_to_qstring start";
    int counter = 0;
    QString line = "";
    for (int i = 0; i < arr.size(); i++, counter++){
        for (int j = 0; j < arr[i].size(); j++){
            line += QString::number(arr[i][j]);
        }
        line += "\n";
    }
    qDebug() << "arr_to_qstring end";
    return line;
}

double func(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

double deriv_func(double a, double b, double c, double x) {
    return 2 * a * x + b;
}

double newton(double a, double b, double c, double initial_guess = 100, double epsilon = 0.0001, int max_iterations = 1000) {
    double x = initial_guess;
    double h = func(a, b, c, x) / deriv_func(a, b, c, x);
    int iterations = 0;

    while (abs(h) >= epsilon && iterations < max_iterations) {
        double deriv = deriv_func(a, b, c, x);
        if (deriv == 0) {
            //Error: Derivative is zero, stopping iteration to avoid division by zero
            return -1;
        }

        h = func(a, b, c, x) / deriv;
        x = x - h;
        iterations++;
    }

    if (iterations == max_iterations) {
        return -1;
        //Warning: Maximum iterations reached, solution may not be accurate
    }

    return x;
}

void Task1::on_pushButton_Send_clicked()
{
    if (this->ui->label_Task1->isVisible()) {
        double a = this->ui->lineEdit_Task1->text().toDouble();
        double b = this->ui->lineEdit2_Task1->text().toDouble();
        double c = this->ui->lineEdit3_Task1->text().toDouble();
        double result = newton(a, b, c);
        QString prompt = QString::number(a) + "&" + QString::number(b) + "&" + QString::number(c);
        if (result == -1){
            this->ui->label_Result_meaning->setText("ERROR");
        }
        else{
            this->ui->label_Result_meaning->setText(QString::number(result));
        }
        emit send_to_server(1, prompt);
    }
    else if (this->ui->label_Task2->isVisible()){
        setmsg(this->ui->lineEdit_Task2->text(), this->ui->lineEdit2_Task2->text());
        this->ui->label_Result_meaning->setText(getmsg(this->ui->lineEdit_Task2->text()));
        emit send_to_server(2, this->ui->lineEdit_Task2->text() + "&" + this->ui->lineEdit2_Task2->text());
    }
    else{
        std::vector<std::vector<int>> arr = qstring_to_arr(this->ui->lineEdit_Task3->text());

        this->ui->label_Result_meaning->setText(arr_to_qstring(arr, this->ui->lineEdit2_Task3->text().toInt()));

        emit send_to_server(3, this->ui->lineEdit2_Task3->text() + "&" + this->ui->lineEdit_Task3->text());
    }
}
