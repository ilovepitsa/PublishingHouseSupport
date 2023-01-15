#ifndef WORKERS_H
#define WORKERS_H

#include <QWidget>
#include "editwindow.h"

namespace Ui {
class workers;
}

class workers : public QWidget
{
    Q_OBJECT

public:
    explicit workers(QWidget *parent = nullptr);
    ~workers();
    void display();
    void editClose();
private slots:
    void on_pushButton_startEdit_clicked();

    void on_pushButton_sendToTypgr_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::workers *ui;
    EditWindow editWindow_ui;
    void checkOrdToEdit();
    void checkOrdToPrint();
signals:
    void workerClose();
};

#endif // WORKERS_H
