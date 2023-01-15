#include "editwindow.h"
#include "ui_editwindow.h"
#include "workers.h"
#include <QtSql>
EditWindow::EditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_lineEdit_NumberPage_textEdited(const QString &arg1)
{
    numberPage=arg1.toInt();
}


void EditWindow::on_lineEdit_ISBN_textEdited(const QString &arg1)
{
    isbn=arg1;
}

QString EditWindow::getTitle() const
{
    return title;
}

void EditWindow::setTitle(const QString &newTitle)
{
    title = newTitle;
}

void EditWindow::setAuthor(const QString &newAuthor)
{
    author = newAuthor;
}

QString EditWindow::getAuthor() const
{
    return author;
}

void EditWindow::display(workers* parent)
{
    ui->label_writeAuthor->setText(author);
    ui->label_writeTitle->setText(title);
    this->show();
    parent_m = parent;
}


void EditWindow::on_pushButton_complete_clicked()
{

    if(!isbn.isEmpty() || numberPage)
    {
        QString str_t = "update editions set edition_code = '%1', volume = %2 where order_number = %3;";
        QSqlQuery query;
        if(query.exec(str_t.arg(isbn).arg(numberPage).arg(orderNumber)))
        {
            parent_m->editClose();
            parent_m->display();
            this->close();
        }
        else
        {
            qDebug()<<"bag";
        }
    }
}

void EditWindow::setOrderNumber(int newOrderNumber)
{
    orderNumber = newOrderNumber;
}

