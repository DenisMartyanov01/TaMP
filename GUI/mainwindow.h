#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task1.h"
#include "task2.h"
#include "task3.h"
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
public slots:
    void on_return();

private:
    Ui::MainWindow *ui;
    Statistics* statistics;
    Task1* task1;
    Task2* task2;
    Task3* task3;
    //auth_reg* ui_reg;
};
#endif // MAINWINDOW_H
