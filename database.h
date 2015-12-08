#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QSqlTableModel>
#include <QTableView>
#include <QObject>

/*
Class Database provides methods to work with database.
Currently uses SQLite for default database.
*/
class Database
{
public:
    Database();
    ~Database();
    int connect(); // Connect LiteSQL-database and create table
    int insert(QString, QString); // Insert data to the table
    QSqlTableModel* constructModel(); // Construct model for displaying DB content in a view
};

#endif // DATABASE_H
