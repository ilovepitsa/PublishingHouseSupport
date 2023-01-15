#ifndef AUTH_H
#define AUTH_H

#include <QWidget>

namespace Ui {
class auth;
}

class auth : public QWidget
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = nullptr);
    ~auth();
    QString getName();
    QString getPassword();
    void ClearLine();
signals:
    void auth_button_clicked();
private slots:
    void on_pushButton_auth_clicked();

    void on_lineEdit_pass_textEdited(const QString &arg1);

    void on_lineEdit_name_textEdited(const QString &arg1);

private:
    Ui::auth *ui;

    QString user_name;
    QString user_password;
};

#endif // AUTH_H
