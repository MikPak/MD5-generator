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
    ui->tableView->setModel(litesql.constructModel());

    for (int col=0; col<2; col++)
    {
       ui->tableView->setColumnWidth(col,250);
    }
}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}

void DatabaseDialog::on_pushButton_Close_clicked()
{
    this->close();
}
