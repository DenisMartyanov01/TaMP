#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "auth_reg.h"

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

private:
    Ui::MainWindow *ui;
    //auth_reg* ui_reg;
};
#endif // MAINWINDOW_H
