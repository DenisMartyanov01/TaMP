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
        this->ui->label2_Task1->hide();
        this->ui->lineEdit_Task1->hide();
        this->ui->lineEdit2_Task1->hide();
        this->ui->lineEdit3_Task1->hide();
        this->ui->lineEdit4_Task1->hide();
        this->ui->lineEdit5_Task1->hide();
        this->ui->label_Task3->hide();
        this->ui->lineEdit_Task3->hide();
        this->ui->lineEdit2_Task3->hide();
        break;
    case 3:
        this->ui->label_Task1->hide();
        this->ui->label2_Task1->hide();
        this->ui->lineEdit_Task1->hide();
        this->ui->lineEdit2_Task1->hide();
        this->ui->lineEdit3_Task1->hide();
        this->ui->lineEdit4_Task1->hide();
        this->ui->lineEdit5_Task1->hide();
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
    int V = graph.size();
    std::vector<std::vector<int>> dist(V, std::vector<int>(V, std::numeric_limits<int>::max()));

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];

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

std::vector<std::vector<int>> allShortestPaths(const std::vector<std::vector<int>>& graph)
{
    QString task = "";

    for (const auto& innerVector : graph)
    {
        for (int value : innerVector)
        {
            task += QString::number(value) + " ";
        }
    }

    std::vector<std::vector<int>> shortestPaths = floydWarshall(graph);

    return shortestPaths;
}

std::vector<std::vector<int>> qstring_to_arr(QString str, int length)
{
    QTextStream stream(&str);
    std::vector<std::vector<int>> array;
    std::vector<int> temp_array;
    int number, counter = 0;
    while (!stream.atEnd()) {
        stream >> number;
        temp_array.push_back(number);
        counter++;
        if (counter >= length){
            counter = 0;
            array.push_back(temp_array);
            temp_array.clear();
        }
    }

    std::vector<std::vector<int>> arr;
    arr = allShortestPaths(array);
    return arr;
}

QString arr_to_qstring(std::vector<std::vector<int>> arr)
{
    int counter = 0;
    QString line = "";
    for (unsigned long long i = 0; i < arr.size(); i++, counter++){
        for (unsigned long long j = 0; j < arr[i].size(); j++){
            line += QString::number(arr[i][j]);
            if (j + 1 < arr[i].size()){
                line += "\t";
            }
        }
        line += "\n";
    }
    return line;
}

double func(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

double deriv_func(double a, double b, double x) {
    return 2 * a * x + b;
}

bool diff_sign(double first, double second)
{
    if ((first > 0 && second <= 0) || (first <= 0 && second > 0)){
        return true;
    }
    return false;
}

double newton(double a, double b, double c, double left, double right)
{
    if (right <= left) {
        return -1.0001;
    }
    double d = (right - left) / 1000;
    double x = func(a, b, c, left);
    double delta_x = left + d;
    while (delta_x <= right){
        if (diff_sign(x, func(a, b, c, delta_x))){
            return delta_x - (func(a, b, c, delta_x) / deriv_func(a, b, delta_x));
        }
        delta_x += d;
    }
    return -1.0001;
}

void Task1::on_pushButton_Send_clicked()
{
    if (this->ui->label_Task1->isVisible()) {
        double a = this->ui->lineEdit_Task1->text().toDouble();
        double b = this->ui->lineEdit2_Task1->text().toDouble();
        double c = this->ui->lineEdit3_Task1->text().toDouble();
        double left = this->ui->lineEdit4_Task1->text().toDouble();
        double right = this->ui->lineEdit5_Task1->text().toDouble();
        double result = newton(a, b, c, left, right);
        QString prompt = QString::number(a) + "&" +
                         QString::number(b) + "&" +
                         QString::number(c) + "&" +
                         QString::number(left) + "&" +
                         QString::number(right);
        if (result == -1.0001){
            this->ui->label_Result_meaning->setText("ERROR, there are no roots in this range");
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
        std::vector<std::vector<int>> arr = qstring_to_arr(
            this->ui->lineEdit_Task3->text(), this->ui->lineEdit2_Task3->text().toInt());

        this->ui->label_Result_meaning->setText(arr_to_qstring(arr));

        emit send_to_server(3, this->ui->lineEdit2_Task3->text() + "&" + this->ui->lineEdit_Task3->text());
    }
}
