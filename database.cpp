#include "Database.h"

Database::Database()
{

}

Database::~Database() {

}

int Database::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hash.db3");
    if(db.open()) {
        qDebug() << "DB connection " << db.connectionName() <<
                   " established";
        QSqlQuery query;
        query.exec("create table hashes(id INTEGER PRIMARY KEY, "
                   "string varchar(100),"
                   "hash varchar(32))");

        return 1;
    } else {
        return 0;
    }
}

int Database::insert(QString hash, QString filename) {
        QSqlQuery query;
        query.prepare("INSERT INTO hashes (id,string, hash) "
                      "VALUES (NULL, ?, ?)");
        query.addBindValue(filename);
        query.addBindValue(hash);

        if(!query.exec()) {
            qDebug() << "Error running query:" << query.lastError();
            return 0;
        } else {
            return 1;
        }
        qDebug() << hash << " " << filename;
}
