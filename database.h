#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QString>

class Database
{
public:
    Database();
    ~Database();
    int connect();
    int insert(QString, QString);
};

#endif // DATABASE_H