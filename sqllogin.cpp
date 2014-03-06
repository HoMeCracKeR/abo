#include "sqllogin.h"
#include "exceptions.h"

SqlLogin::SqlLogin(QString username,QString password)
{
    this->username=username;
    this->password=password;
    mydb=QSqlDatabase::addDatabase("QSQLITE");//SQL_DRIVER);
    mydb.setDatabaseName("database/abo.db");//DATABASE_LOCATION);
    if(!mydb.isOpen())
    {
        mydb.open();
        qDebug()<<"Database is open...";

    }
    else
    {
        qDebug()<<"Database is already open...";
    }
}
void SqlLogin::ExecuteQuery()
{
    //query=new QSqlQuery;
    //
    if(query.exec("SELECT * FROM login WHERE username='"+username+"' and password='"+password+"'"))
    {
        int count=0;
        while(query.next())
            count++;
        if(count==1)
        {
            //found an username and password
            loginSucces=true;
        }
        else
            loginSucces=false;
    }
    else
    {
        loginSucces=false;
        throw QueryExceptions("Query didn't executed!\n");
    }

}
bool SqlLogin::GetLoginSucces()
{
    return loginSucces;
}
SqlLogin::~SqlLogin(){

}
