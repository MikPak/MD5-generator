#include <QSqlTableModel>
#include <QTableView>
#include <QObject>
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

void Database::constructModel() {
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("hashes");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("string"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("hash"));

    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();

}
