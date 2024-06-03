#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task1.h"
#include "statistics.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Exit_clicked();
    //void slot_on_auth_ok();
    void on_pushButton_Task1_clicked();
    void on_pushButton_Task2_clicked();
    void on_pushButton_Task3_clicked();
    void on_pushButton_Stats_clicked();

signals:
    void send_task(int, QString);
    void sort_request_main();
    void request_lookmystat_main();
    void request_lookallstat_main();
    void request_sort_main(QString);

public slots:
    void on_return();
    void on_send_task(int, QString);
    void on_request_sort(QString);
    void on_request_lookmystat();
    void on_request_lookallstat();

private:
    Ui::MainWindow *ui;
    void task_n(int i);
    //auth_reg* ui_reg;
};
#endif // MAINWINDOW_H
