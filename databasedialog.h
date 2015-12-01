#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseDialog(QWidget *parent = 0);
    ~DatabaseDialog();

private:
    Ui::DatabaseDialog *ui;
};

#endif // DATABASEDIALOG_H
