#include "databasedialog.h"
#include "ui_databasedialog.h"
#include "QtSql/qsqlquerymodel.h"
DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    ui->setupUi(this);
    //Let's load the sqlite db
    //QSqlQueryModel * model = new QSqlQueryModel();
    //open db
    //QSqlQuery* query = new QSqlQuery(/*DB here*/);

    //query->prepare();
    //query->exec();
    //model->setQuery(*query);
    //ui->tableView->setModel(model);


}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}
