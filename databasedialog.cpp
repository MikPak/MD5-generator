#include "databasedialog.h"
#include "ui_databasedialog.h"
#include "QtSql/qsqlquerymodel.h"
#include "database.h"
DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    Database litesql;
    ui->setupUi(this);

    QTableView *view = new QTableView();
    ui->tableView->setModel(litesql.constructModel());
    /*view->setModel(litesql.constructModel());
    ui->tableView = view;
    ui->tableView->;*/
}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}

void DatabaseDialog::on_pushButton_Close_clicked()
{
    this->close();
}
