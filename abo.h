#ifndef ABO_H
#define ABO_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
namespace Ui {
class Abo;
}

class Abo : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Abo(QWidget *parent = 0);
    ~Abo();
private slots:
    void LoginToDatabase();
private:
    Ui::Abo *ui;
    QMenuBar *menuBar;
    QAction *open, *print,*recent,*exit,*add,*loginAct;
    QMenu *file,*settings, *help;
    QLineEdit *usernameEdit, *passwordEdit;
    QPushButton *addBookButton,*updateButton;
    QListWidget *listView;
    QLabel *statusLabel;
    QListWidgetItem *item;
private:
    void InitElements(Ui::Abo *);
    void SetActions();
private:
    bool isLoggedIn;
};
//    item=new QListWidgetItem();
//    item->setText(tr("Logged in..."));
//    listView->addItem(item);

#endif // ABO_H
