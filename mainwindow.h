#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "auth.h"
#include "client.h"
#include "workers.h"
#include "manager.h"
#include <QtSql>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display();

    bool connect_db();

private:

    QSqlDatabase data_base;
    QString db_input;
    QString user_name;
    QString user_password;
    bool success_login;
    Ui::MainWindow *ui;
    auth auth_ui;
    client client_ui;
    manager manager_ui;
    workers workers_ui;

private slots:
    void auth_user();
    void addOrder();
    void updateManagersOrders();
    void updateManagersTyph();

    void closeClient();
    void closeManager();
    void closeWorker();
};
#endif // MAINWINDOW_H
