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

    username=usernameEdit->text();
    password=passwordEdit->text();

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

    loginThread.start();
    if(logSuccess==true)
        ui->controlLabel->setText("true");
    else
        ui->controlLabel->setText("true");
}

void Dialog::on_cancelButton_clicked()
{
    hide();
}
bool Dialog::getLogSuccess()
{
    return logSuccess;
}
void Dialog::run()
{
    if(!username.isEmpty() || !password.isEmpty())
    {
        SqlLogin login=SqlLogin(username,password);
        login.ExecuteQuery();
        logSuccess=login.GetLoginSucces();
        loginThread.disconnect();
    }
}
