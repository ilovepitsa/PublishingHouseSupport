#include "auth.h"
#include "ui_auth.h"

auth::auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
}

auth::~auth()
{
    delete ui;
}

QString auth::getName()
{
    return user_name;
}

QString auth::getPassword()
{
    return user_password;
}

void auth::ClearLine()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_pass->clear();
}

void auth::on_pushButton_auth_clicked()
{
    emit auth_button_clicked();
}


void auth::on_lineEdit_pass_textEdited(const QString &arg1)
{
    user_name=arg1;
}


void auth::on_lineEdit_name_textEdited(const QString &arg1)
{
    user_password=arg1;
}

