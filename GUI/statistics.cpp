#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) : QWidget(parent), ui(new Ui::Statistics)
{
    ui->setupUi(this);
    this->setWindowTitle("The Amazing Miracle App (TAMP)");
    this->isMyStat(true);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::on_statistics_return_clicked()
{
    emit on_return();
    this->close();
}


void Statistics::on_pushButton_myStat_clicked()
{
    this->ui->label_error->setText("");
    this->ui->label_logins->setText("");
    emit request_lookmystat();
}


void Statistics::on_pushButton_allStat_clicked()
{
    this->ui->label_error->setText("");
    this->ui->label_logins->setText("");
    emit request_lookallstat();
}


void Statistics::on_pushButton_Sort_clicked()
{
    this->ui->label_error->setText("");
    this->ui->label_logins->setText("");
    emit request_sort(this->ui->lineEdit_sort->text());
}

void Statistics::slot_error(QString line)
{
    this->ui->label_error->setText(line);
}

void Statistics::isMyStat(bool state)
{
    if (state) {
        this->ui->label_username->hide();
        this->ui->label_newton->hide();
        this->ui->label_music->hide();
        this->ui->label_graph->hide();
        this->ui->list_username->hide();
        this->ui->list_newton->hide();
        this->ui->list_music->hide();
        this->ui->list_graph->hide();
        this->ui->label_Newton->show();
        this->ui->label_Music->show();
        this->ui->label_Graph->show();
        this->ui->label_logins->show();
        this->ui->label_Graph_meaning->show();
        this->ui->label_Music_meaning->show();
        this->ui->label_Newton_meaning->show();
    }
    else {
        this->ui->label_Newton->hide();
        this->ui->label_Music->hide();
        this->ui->label_Graph->hide();
        this->ui->label_logins->hide();
        this->ui->label_Graph_meaning->hide();
        this->ui->label_Music_meaning->hide();
        this->ui->label_Newton_meaning->hide();
        this->ui->label_username->show();
        this->ui->label_newton->show();
        this->ui->label_music->show();
        this->ui->label_graph->show();
        this->ui->list_username->show();
        this->ui->list_newton->show();
        this->ui->list_music->show();
        this->ui->list_graph->show();
    }

}

void Statistics::received_mystat(int graph, int music, int newton)
{
    this->ui->label_Graph_meaning->setText(QString::number(graph));
    this->ui->label_Music_meaning->setText(QString::number(music));
    this->ui->label_Newton_meaning->setText(QString::number(newton));
    this->isMyStat(true);
}

void Statistics::received_allstat(QString logins, QString graph, QString music, QString newton)
{
    QStringListModel* model_users = new QStringListModel();
    QStringListModel* model_newton = new QStringListModel();
    QStringListModel* model_music = new QStringListModel();
    QStringListModel* model_graph = new QStringListModel();
    QStringList users, newtons, musics, graphs;
    users << logins.split(' ');
    newtons << newton.split(' ');
    musics << music.split(' ');
    graphs << graph.split(' ');
    model_users->setStringList(users);
    model_newton->setStringList(newtons);
    model_music->setStringList(musics);
    model_graph->setStringList(graphs);
    this->ui->list_username->setModel(model_users);
    this->ui->list_newton->setModel(model_newton);
    this->ui->list_music->setModel(model_music);
    this->ui->list_graph->setModel(model_graph);
    this->isMyStat(false);
}
