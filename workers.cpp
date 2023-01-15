#include "workers.h"
#include "ui_workers.h"
#include <thread>
#include <mutex>
#include <QtSql>
workers::workers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workers)
{
    ui->setupUi(this);
}

workers::~workers()
{
    delete ui;
}

void workers::display()
{
    checkOrdToEdit();
    this->show();
    this->focusWidget();
}

void workers::checkOrdToPrint()
{
    QString str_t = "select order_number from orders where status = 'edited';";
    QString db_input= str_t;
    QSqlQuery query;
    QSqlRecord rec;
    ui->listWidget_2->clear();
    if(query.exec(db_input))
    {
        rec=query.record();
        while(query.next())
        {
            ui->listWidget_2->addItem(query.value(rec.indexOf("order_number")).toString());
        }
    }
}



void workers::on_pushButton_startEdit_clicked()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto currOrd = ui->listWidget->currentItem();
    auto ord = currOrd->text().toInt();
    qDebug()<<ord;
    QString str_t="select * from editions where order_number = %1;";
    QString db_input=str_t.arg(ord);
    QSqlQuery query;
    if(query.exec(db_input))
    {
        auto rec = query.record();
        query.next();
        qDebug()<<"here";
        auto author = query.value(rec.indexOf("Author")).toString();
                qDebug()<<"here1";
        auto title = query.value(rec.indexOf("title")).toString();
        editWindow_ui.setAuthor(author);
        editWindow_ui.setTitle(title);
        editWindow_ui.setOrderNumber(ord);
        this->hide();
        editWindow_ui.display(this);
    }
}

void workers::on_pushButton_sendToTypgr_clicked()
{
    auto currOrd = ui->listWidget_2->currentItem();
    auto ord = currOrd->text().toInt();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    QString str_t="update orders set status = 'completed' where order_number=%1";
    QString db_input = str_t.arg(ord);
    QSqlQuery query;
    QSqlRecord rec;
    if(!query.exec(db_input))
    {
        qDebug()<<"failed";
    }
    checkOrdToEdit();
    checkOrdToPrint();
}

void workers::editClose()
{
    this->show();
    auto currOrd = ui->listWidget->currentItem();
    auto ord = currOrd->text().toInt();
    QString str_t="update orders set status = 'edited' where order_number=%1";
    QString db_input = str_t.arg(ord);
    QSqlQuery query;
    QSqlRecord rec;
    if(!query.exec(db_input))
    {
        qDebug()<<"failed";
    }
    checkOrdToEdit();
    checkOrdToPrint();
}

void workers::checkOrdToEdit()
{

    QString str_t = "select order_number from orders where status = 'not_edited';";
    QString db_input= str_t;
    QSqlQuery query;
    QSqlRecord rec;
    ui->listWidget->clear();
    if(query.exec(db_input))
    {
        rec=query.record();
        while(query.next())
        {
            ui->listWidget->addItem(query.value(rec.indexOf("order_number")).toString());
        }
    }

}



void workers::on_pushButton_back_clicked()
{
    emit workerClose();
}

