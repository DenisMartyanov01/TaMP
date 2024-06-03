#ifndef TASK1_H
#define TASK1_H
#include <QWidget>
#include <QCoreApplication>
#include <QFile>
#include <QDir>

namespace Ui {
class Task1;
}

class Task1 : public QWidget
{
    Q_OBJECT

public:
    explicit Task1(QWidget *parent = nullptr);
    void set_task(int i);
    ~Task1();

private slots:
    void on_task1_return_clicked();
    void on_pushButton_Send_clicked();

private:
    Ui::Task1 *ui;
    QString getmsg(QString);
    void setmsg(QString, QString);

signals:
    void on_return();
    void send_to_server(int, QString);
};

#endif // TASK1_H
