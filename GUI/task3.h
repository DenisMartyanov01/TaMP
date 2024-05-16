#ifndef TASK3_H
#define TASK3_H

#include <QWidget>

namespace Ui {
class Task3;
}

class Task3 : public QWidget
{
    Q_OBJECT

public:
    explicit Task3(QWidget *parent = nullptr);
    ~Task3();

private slots:
    void on_task3_return_clicked();

private:
    Ui::Task3 *ui;

signals:
    void on_return();
};

#endif // TASK3_H
