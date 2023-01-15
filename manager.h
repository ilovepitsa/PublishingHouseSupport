#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include <QtWidgets/QListWidget>

#include "Types.h"
#include "edittyporg.h"
namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = nullptr);
    ~manager();
    void display();
    void checkNewOrders();
    void checkNewTyph();

    Ui::manager *getUi() const;
    void addOrderNumber(int orderNumber);
    void addTypNumber(TypInfo TypOrderNumber);
signals:
    void signalToCheckOrders();
    void signalToCheckTyph();
    void managerClose();
private slots:
    void on_pushButton_update_clicked();

    void on_pushButton_back_clicked();
    void editTypgrClose();
    void on_pushButton_EditTyp_clicked();

    void on_pushButton_getInfo_clicked();

private:
    Ui::manager *ui;
    QListWidget *OrderList;
    QListWidget *TypList;
    EditTyporg edittypgr;
    void infoInFile();
};

#endif // MANAGER_H
