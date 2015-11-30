#include <QtSql/QtSql>
#include <QString>
#include <QFile>
#include <QDir>
#include <QCoreApplication>

QSqlDatabase db;
QDir dir;
QString dbName = "hash.db3";

int init(){
    //Where are we?
    dir(QCoreApplication::applicationDirPath());
    //let's search for database

    dir.setFilter(QDir::Files);
    QStringList qsl;
    qsl.append(dbName); //only a file with appropriate name is wanted
    dir.setNameFilters(qsl);

    return 1;
}

int setupDb(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    return 1;
}

int connect(){
    if(db.open()) {
        qDebug() << ">DB connection" << db.databaseName() << "established";
    }

    return 1;
}

int close(){
    db.close();
    return 1;
}
