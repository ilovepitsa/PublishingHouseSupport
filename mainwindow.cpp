#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Types.h"
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    connect(&auth_ui,SIGNAL(auth_button_clicked()),this,SLOT(auth_user()));
    connect(&auth_ui,SIGNAL(destroyed()),this,SLOT(show()));
    connect(&client_ui,SIGNAL(destroyed()),&auth_ui,SLOT(show()));
    connect(&client_ui,SIGNAL(addOrder_button_clicked()),this,SLOT(addOrder()));
    connect(&manager_ui,SIGNAL(signalToCheckOrders()),this,SLOT(updateManagersOrders()));
    connect(&manager_ui,SIGNAL(signalToCheckTyph()),this,SLOT(updateManagersTyph()));
    connect(&client_ui,SIGNAL(client_close()),this,SLOT(closeClient()));
    connect(&manager_ui,SIGNAL(managerClose()),this,SLOT(closeManager()));
    connect(&workers_ui,SIGNAL(workerClose()),this,SLOT(closeWorker()));

    if(!connect_db())
    {
        qDebug()<<"cat connect";
    }
    success_login = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display()
{
    //client_ui.show();
    auth_ui.show();
}

void MainWindow::auth_user()
{
    QSqlQuery query;
    user_name = auth_ui.getName();
    user_password = auth_ui.getPassword();

    QString str_t = "SELECT * "
                    "FROM users "
                    "WHERE login = '%1';";
    db_input = str_t.arg(user_name);
    if(!query.exec(db_input))
    {
        qDebug()<<"cant find user";
    }
    else
    {
        QSqlRecord rec = query.record();
        query.next();
        QString user_name1 = "";
        QString user_pass1="";
        user_name1 = query.value(rec.indexOf("login")).toString();
        user_pass1 = query.value(rec.indexOf("password")).toString();
        if(user_name1 != user_name || user_pass1 != user_password)
        {
            success_login=false;
        }
        else
        {
            success_login = true;
            auth_ui.hide();
            if(user_name=="client")
            {
                client_ui.show();
            }
            else if(user_name=="manager")
            {
                manager_ui.display();
            }
            else if(user_name=="worker")
            {
                workers_ui.display();
            }

        }
    }
}

void MainWindow::addOrder()
{
    auto LastName = client_ui.getLastName();
    auto FirstName = client_ui.getFirstName();
    auto MiddleName = client_ui.getMiddleName();
    auto Pasport = client_ui.getPasport();
    auto Birthday = client_ui.getBirthday();
    auto Author = client_ui.getAuthor();
    auto count = client_ui.getCount();
    auto title = client_ui.getTitle();
    QString status ="new";
    QString str_customers = "select * from customers "
                            "where pasport='%1';";

    QSqlQuery query;
    db_input = str_customers.arg(Pasport);
    QSqlRecord rec;
    if(query.exec(db_input))
    {
        rec=query.record();
        if(!query.next())
        {
            str_customers = "INSERT INTO customers (pasport,LastName,FirstName,MiddleName,Birthday) "
                            "VALUES ('%1','%2','%3','%4','%5');";
            qDebug()<<rec.indexOf("pasport");
            db_input = str_customers.arg(Pasport).arg(LastName).arg(FirstName).arg(MiddleName).arg(Birthday);
            query.exec(db_input);
        }
        else
        {
            qDebug()<<query.value(rec.indexOf("pasport")).toString();
        }

    }


            ;
    QString str_orders= "INSERT INTO orders (pasport,count_list,Number_of_Typhogr) "
                        "VALUES ('%1',%2,%3);";
    db_input = str_orders.arg(Pasport).arg(count).arg(5);
    if(!query.exec(db_input))
    {
        qDebug()<<"aaa "<<query.lastError().text();
    }
    str_orders="select order_number from orders where pasport='%1'";
    db_input=str_orders.arg(Pasport);
    if(!query.exec(db_input))
    {
        qDebug()<<"bbb "<<query.lastError().text();
    }
    rec=query.record();
    int ordnmbr=0;
     if(query.last())
     {
         ordnmbr=query.value(rec.indexOf("order_number")).toInt();
     }
    QString str_edit= "INSERT INTO editions (order_number,Author,title) "
                      "VALUES ('%1','%2','%3');";
    db_input = str_edit.arg(ordnmbr).arg(Author).arg(title);
    if(!query.exec(db_input))
    {
        qDebug()<<"ccc "<<query.lastError().text();
    }
}

void MainWindow::updateManagersOrders()
{

    QString str_t = "select order_number from orders where status = 'new';";
    db_input= str_t;
    QSqlQuery query;
    QSqlRecord rec;
    if(query.exec(db_input))
    {
        rec=query.record();
        while(query.next())
        {
           manager_ui.addOrderNumber(query.value(rec.indexOf("order_number")).toInt());
        }
    }
}

void MainWindow::updateManagersTyph()
{
    QString str_t = "select * from typography where number_typography <> 5;";
    db_input = str_t;
    QSqlQuery query;
    QSqlRecord rec;
    if(query.exec(db_input))
    {
        rec=query.record();
        while(query.next())
        {
            TypInfo typinf={query.value(rec.indexOf("number_typography")).toInt(),query.value(rec.indexOf("adress_typ")).toString(),query.value(rec.indexOf("number_telephone")).toString()};
           manager_ui.addTypNumber(typinf);
        }
    }
}

void MainWindow::closeClient()
{
    auth_ui.ClearLine();
    client_ui.hide();
    auth_ui.show();
}

void MainWindow::closeManager()
{
    auth_ui.ClearLine();
    manager_ui.hide();
    auth_ui.show();
}

void MainWindow::closeWorker()
{
    auth_ui.ClearLine();
    workers_ui.hide();
    auth_ui.show();
}

bool MainWindow::connect_db()
{
    data_base=QSqlDatabase::addDatabase("QMYSQL");
    data_base.setDatabaseName("izdatelstwo");
    data_base.setHostName("127.0.0.1");
    data_base.setUserName("root");
    data_base.setPassword("zxasqw123qwaszx");
    if(!data_base.open())
    {
        qDebug()<<"cant open";
        return false;
    }
    return true;
}

