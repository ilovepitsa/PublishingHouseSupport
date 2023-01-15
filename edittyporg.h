#ifndef EDITTYPORG_H
#define EDITTYPORG_H

#include <QWidget>


namespace Ui {
class EditTyporg;
}

class EditTyporg : public QWidget
{
    Q_OBJECT

public:
    explicit EditTyporg(QWidget *parent = nullptr);
    ~EditTyporg();
    void display();
private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();


    void on_pushButton_clicked();

private:
    Ui::EditTyporg *ui;
    void updateinfo();
signals:
    void close();
};

#endif // EDITTYPORG_H
