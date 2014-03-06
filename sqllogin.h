#ifndef SQLLOGIN_H
#define SQLLOGIN_H
#include <QtSql>
#include <QDebug>
#include<QFileInfo>
class SqlLogin
{
public:
    SqlLogin(QString,QString);
    ~SqlLogin();
private:
    QSqlDatabase mydb;
    QSqlQuery query;
    QString username,password;
    const std::string SQL_DRIVER="QSQLITE";
    const std::string DATABASE_LOCATION="database/abo.db";
    bool loginSucces;
public:
    void ExecuteQuery();
    bool GetLoginSucces();
};

#endif // SQLLOGIN_H
