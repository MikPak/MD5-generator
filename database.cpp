#include "database.h"

Database::Database()
{

}

Database::~Database() {

}

/*
int Database::connect()
Connects to the SQLite database and creates table 'hashes', if it
doesn't already exist. Returns int 1 on success.
 */
int Database::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hash.db3");
    if(db.open()) {
        qDebug() << "DB connection " << db.connectionName() <<
                   " established";
        QSqlQuery query;
        query.prepare("create table hashes(id INTEGER PRIMARY KEY, "
                   "string varchar(100),"
                   "hash varchar(32))");
        if(query.exec()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/*
int Database::insert(QString, QString)
Inserts generated hash and respective file name
to the Database. Returns int 1 on success.
 */
int Database::insert(QString hash, QString filename) {
        if(!hash.isEmpty() && !filename.isEmpty()) {
            QSqlQuery query1, query2;
            query1.prepare("INSERT INTO hashes (id,string, hash) "
                          "VALUES (NULL, ?, ?)");
            query1.addBindValue(filename);
            query1.addBindValue(hash);

            // Check if hash already exists in DB
            query2.prepare("Select count(*) from hashes "
                           "where hash=?");
            query2.addBindValue(hash);
            if(!query2.exec() || !query2.first()) {
                qDebug() << "Error running query:" << query2.lastError();
                return 0;
            } else {
                if (query2.value(0) != 0) { // If results found
                    qDebug() << query2.value(0);
                    return 0;
                }
            }

            // Insert new hash to DB
            if(!query1.exec()) {
                qDebug() << "Error running query:" << query1.lastError();
                return 0;
            } else {
                return 1;
            }
            qDebug() << hash << " " << filename;
          } else {
            return 0;
        }
}

/*
QSqlTableModel* Database::constructModel()
Constructs QSqlTableModel for displaying database data in a view
 */
QSqlTableModel* Database::constructModel() {
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("hashes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->removeColumn(0); // don't show the ID
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("String/File"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Hash"));

    return model;
}
