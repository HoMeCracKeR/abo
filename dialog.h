#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public:
    bool getLogSuccess();
private slots:
    void on_loginButton_clicked();

    void on_cancelButton_clicked();

private:
    bool logSuccess;
    Ui::Dialog *ui;
    QLineEdit *usernameEdit,*passwordEdit;
    QPushButton *loginButton,*cancelButton;
    void InitComponents();

};

#endif // DIALOG_H
