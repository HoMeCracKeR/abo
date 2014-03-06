#include "abo.h"
#include "ui_abo.h"
#include "dialog.h"
Abo::Abo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Abo)
{
    ui->setupUi(this);
    InitElements(ui);
    SetActions();
}
void Abo::InitElements(Ui::Abo *ui)
{   isLoggedIn=false;

    /*-----Init ListView & statusLabel----*/
    listView=ui->listView;
    statusLabel=ui->statusLabel;
    /*-----Init AddBookButton----*/
    addBookButton=ui->addBookButton;
    addBookButton->setDisabled(true);

    /*-----Init RefreshButton----*/
    updateButton=ui->updateButton;
    updateButton->setDisabled(true);

    /*-----Init LoginAction-----*/
    loginAct=ui->action_Login;
}

void Abo::SetActions()
{
    connect(loginAct,SIGNAL(triggered()),this,SLOT(LoginToDatabase()));

}


void Abo::LoginToDatabase()
{

    if(!isLoggedIn)
    {
    statusLabel->setText(tr("Not Logged in..."));
    Dialog *dialog=new Dialog;
    dialog->show();
    isLoggedIn=dialog->getLogSuccess();


    }
    else
    {
        statusLabel->setText(tr("Logged in..."));
    }
}
Abo::~Abo()
{
    delete ui;
}
