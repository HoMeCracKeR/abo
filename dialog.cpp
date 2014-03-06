#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    InitComponents();
}
void Dialog::InitComponents()
{
    usernameEdit=ui->usernameEdit;
    passwordEdit=ui->passwordEdit;
    loginButton=ui->loginButton;
    cancelButton=ui->cancelButton;

    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
}

Dialog::~Dialog()
{
    delete usernameEdit;
    delete passwordEdit;
    delete loginButton;
    delete cancelButton;
    delete ui;
}

void Dialog::on_loginButton_clicked()
{

}

void Dialog::on_cancelButton_clicked()
{
    hide();
}
bool Dialog::getLogSuccess()
{
    return logSuccess;
}
