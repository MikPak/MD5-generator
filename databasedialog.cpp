#include "databasedialog.h"
#include "ui_databasedialog.h"
#include "QtSql/qsqlquerymodel.h"
DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hash.db3");
    if(db.open()) {
        qDebug() << "DB connection " << db.connectionName() <<
                   " established";
        QSqlQuery query;
        query.exec("create table hashes(id int primary key, "
                   "string varchar(100),"
                   "hash varchar(32))");
    }
    ui->setupUi(this);

}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}

void DatabaseDialog::on_pushButton_Close_clicked()
{
    this->close();
}
