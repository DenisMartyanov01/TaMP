#ifndef TASK1_H
#define TASK1_H

#include <QWidget>

namespace Ui {
class Task1;
}

class Task1 : public QWidget
{
    Q_OBJECT

public:
    explicit Task1(QWidget *parent = nullptr);
    ~Task1();

private slots:
    void on_task1_return_clicked();

private:
    Ui::Task1 *ui;

signals:
    void on_return();
};

#endif // TASK1_H
