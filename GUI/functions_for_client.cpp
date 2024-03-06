#include "functions_for_client.h"

functions_for_client::functions_for_client()
{
    ui_auth = new auth_reg;
    ui_auth->show();
    connect(ui_auth, &auth_reg::is_auth, this, &functions_for_client::is_auth);
}

void functions_for_client::is_auth(QString login, QString password)
{
    if(login == "user" && password == "123"){
        delete ui_auth;
        ui_main = new MainWindow;
        ui_main->show();
    }
}
