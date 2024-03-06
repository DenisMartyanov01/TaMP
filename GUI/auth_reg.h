#ifndef AUTH_REG_H
#define AUTH_REG_H

#include <QWidget>
//#include "functions_for_client.h"

namespace Ui {
class auth_reg;
}

class auth_reg : public QWidget
{
    Q_OBJECT

public:
    explicit auth_reg(QWidget *parent = nullptr);
    ~auth_reg();
    //functions_for_client* get_func();

private slots:
    void on_pushButton_Exit_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_change_clicked();

signals:
    void is_auth(QString, QString);

private:
    Ui::auth_reg *ui;
    //functions_for_client* func;
};

#endif // AUTH_REG_H
