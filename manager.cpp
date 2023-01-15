#include "manager.h"
#include "ui_manager.h"
#include <QtSql>
manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    connect(&edittypgr,SIGNAL(close()),this,SLOT(editTypgrClose()));
    ui->setupUi(this);
    OrderList = new QListWidget(this);
    TypList = new QListWidget(this);
    ui->gridLayout->addWidget(OrderList,1,0);
    ui->gridLayout->addWidget(TypList,1,2);
}

manager::~manager()
{
    delete ui;
}

void manager::display()
{
    checkNewOrders();
    checkNewTyph();
    this->show();
}

void manager::checkNewOrders()
{
    emit signalToCheckOrders();
}

void manager::checkNewTyph()
{
    emit signalToCheckTyph();
}

Ui::manager *manager::getUi() const
{
    return ui;
}

void manager::addOrderNumber(int orderNumber)
{
    QString str = "%1";

    OrderList->addItem(str.arg(orderNumber));
}

void manager::addTypNumber(TypInfo TypOrderNumber)
{
    QString str = "%1";
    QString tmp=str.arg(TypOrderNumber.number);//.arg(TypOrderNumber.adress).arg(TypOrderNumber.number_tel);
    TypList->addItem(tmp);
}

void manager::on_pushButton_update_clicked()
{
    qDebug()<<"update clicked";
    auto curItemOrd = OrderList->currentItem();
    auto curItemTyp = TypList->currentItem();
    auto typ = curItemTyp->text().toInt();
    auto ord = curItemOrd->text().toInt();
    QString str_t = "update orders set status = 'not_edited',Number_of_Typhogr = %1  where order_number=%2;";
    QString db_input=str_t.arg(typ).arg(ord);
    QSqlQuery query;
    if(!query.exec(db_input))
    {
        qDebug()<<"aa"<<query.lastError()<<" "<<typ;
    }

    OrderList->clear();

    checkNewOrders();
}


void manager::on_pushButton_back_clicked()
{
    emit managerClose();
}

void manager::editTypgrClose()
{
    this->display();
}


void manager::on_pushButton_EditTyp_clicked()
{
    this->hide();
    edittypgr.display();
}


void manager::on_pushButton_getInfo_clicked()
{
    infoInFile();
}

void manager::infoInFile()
{

}

