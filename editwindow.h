#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>

class workers;
namespace Ui {
class EditWindow;
}

class EditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

    QString getAuthor() const;
    void display(workers    * parent);
    void setAuthor(const QString &newAuthor);

    QString getTitle() const;
    void setTitle(const QString &newTitle);

    void setOrderNumber(int newOrderNumber);

private slots:
    void on_lineEdit_NumberPage_textEdited(const QString &arg1);

    void on_lineEdit_ISBN_textEdited(const QString &arg1);

    void on_pushButton_complete_clicked();

private:
    Ui::EditWindow *ui;
    workers *parent_m;
    QString author;
    QString title;
    QString isbn;
    int orderNumber;
    int numberPage=0;
};

#endif // EDITWINDOW_H
