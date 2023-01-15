#include "client.h"
#include "ui_client.h"
#include <QMessageBox>
client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}



void client::on_lineEdit_firstName_textEdited(const QString &arg1)
{
    firstName=arg1;
}


void client::on_lineEdit_LastName_textEdited(const QString &arg1)
{
    lastName=arg1;
}


void client::on_lineEdit_MiddleName_textEdited(const QString &arg1)
{
    MiddleName=arg1;
}


void client::on_lineEdit_Birhday_textEdited(const QString &arg1)
{
    Birthday = arg1;
}


void client::on_lineEdit_pasport_textEdited(const QString &arg1)
{
    tempPasport=arg1;
}


void client::on_lineEdit_Author_textEdited(const QString &arg1)
{
    author=arg1;
}


void client::on_lineEdit_8_textEdited(const QString &arg1)
{
    title=arg1;
}


void client::on_lineEdit_Count_textEdited(const QString &arg1)
{
    foreach(auto i , arg1)
    {
        if(!i.isDigit())
        {
            QMessageBox::warning(this,"Внимание","неверные данные");
            return;
        }
    }
    count=arg1.toInt();
}


void client::on_pushButton_addOrder_clicked()
{
    emit addOrder_button_clicked();
}

int client::getCount() const
{
    return count;
}

QString client::getTitle() const
{
    return title;
}

QString client::getAuthor() const
{
    return author;
}

QString client::getPasport() const
{
    return pasport;
}

QString client::getBirthday() const
{
    return Birthday;
}

QString client::getMiddleName() const
{
    return MiddleName;
}

QString client::getLastName() const
{
    return lastName;
}

QString client::getFirstName() const
{
    return firstName;
}


void client::on_lineEdit_pasport_editingFinished()
{
    if(tempPasport.length()==10)
    {
        foreach (auto i, tempPasport)
        {
           if(!i.isDigit())
           {
               break;
               QMessageBox::warning(this,"Внимание","Неправильно введены данные паспорта");
               return;
           }
        }
        pasport=tempPasport;
    }
    else
    {
        QMessageBox::warning(this,"Внимание","Неправильно введены данные паспорта");
        return;
    }
}


void client::on_pushButton_back_clicked()
{
    emit client_close();
}

