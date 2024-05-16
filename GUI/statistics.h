#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>

namespace Ui {
class Statistics;
}

class Statistics : public QWidget
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

private slots:
    void on_statistics_return_clicked();

private:
    Ui::Statistics *ui;

signals:
    void on_return();
};

#endif // STATISTICS_H
