#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    QString getFirstName() const;

    QString getLastName() const;

    QString getMiddleName() const;

    QString getBirthday() const;

    QString getPasport() const;

    QString getAuthor() const;

    QString getTitle() const;

    int getCount() const;

private slots:

    void on_lineEdit_firstName_textEdited(const QString &arg1);

    void on_lineEdit_LastName_textEdited(const QString &arg1);

    void on_lineEdit_MiddleName_textEdited(const QString &arg1);

    void on_lineEdit_Birhday_textEdited(const QString &arg1);

    void on_lineEdit_pasport_textEdited(const QString &arg1);

    void on_lineEdit_Author_textEdited(const QString &arg1);

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_lineEdit_Count_textEdited(const QString &arg1);

    void on_pushButton_addOrder_clicked();

    void on_lineEdit_pasport_editingFinished();

    void on_pushButton_back_clicked();

private:
    Ui::client *ui;
    QString firstName;
    QString lastName;
    QString MiddleName;
    QString Birthday;
    QString pasport;
    QString author;
    QString title;
    int count;
    QString tempPasport;

signals:
    void addOrder_button_clicked();
    void client_close();

};

#endif // CLIENT_H
