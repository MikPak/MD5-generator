#include "databasedialog.h"
#include "ui_databasedialog.h"
#include "QtSql/qsqlquerymodel.h"
DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    ui->setupUi(this);
}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}
