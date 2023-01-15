#include "edittyporg.h"
#include "ui_edittyporg.h"
#include <QInputDialog>
#include <QtSql>
EditTyporg::EditTyporg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditTyporg)
{
    ui->setupUi(this);
}

EditTyporg::~EditTyporg()
{
    delete ui;
}

void EditTyporg::display()
{
    updateinfo();
    this->show();
}

void EditTyporg::on_pushButton_Add_clicked()
{
    QString address = QInputDialog::getText(this,"Address","Enter address");
    QString address_text=address.simplified();
    QString number = QInputDialog::getText(this,"Number Telephone","Enter number telephone");
    QString number_text = number.simplified();

    QString str_t = "insert into typography (adress_typ,number_telephone) values('%1','%2');";
    QString db_input = str_t.arg(address_text).arg(number_text);

    QSqlQuery query;
    if(!query.exec(db_input))
    {
        qDebug()<<"error";
    }
    updateinfo();
}


void EditTyporg::on_pushButton_Remove_clicked()
{
    int r = ui->listWidget->currentRow();
    if(r!=-1)
    {
        auto item = ui->listWidget->takeItem(r);
        QStringList list = item->text().split(QRegularExpression(" "));
        delete item;
        QString str_t = "delete from typography where number_typography=%1;";
        QString db_input =str_t.arg(list[0].toInt());
        QSqlQuery query;
        if(!query.exec(db_input))
        {
            qDebug()<<"cant delete";
        }
    }
}





void EditTyporg::on_pushButton_clicked()
{
    this->hide();
    emit close();
}

void EditTyporg::updateinfo()
{
    ui->listWidget->clear();
    QString str_t ="select * from typography;";
    QSqlQuery query;
    if(query.exec(str_t))
    {
        qDebug()<<"here";
        auto rec = query.record();
        while(query.next())
        {
            if(query.value(rec.indexOf("number_typography")).toInt()!=5)
            {
                QString tmp=query.value(rec.indexOf("number_typography")).toString() + " "+
                        query.value(rec.indexOf("adress_typ")).toString() + " " +
                        query.value(rec.indexOf("number_telephone")).toString();

                ui->listWidget->addItem(tmp);
            }
        }
    }
}

