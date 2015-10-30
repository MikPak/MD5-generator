#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QtSql/QtSql>

#include "hasher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName;
    QTextStream stream(stdin);
    QDir dir(QCoreApplication::applicationDirPath());
    QSqlDatabase db;

    qDebug() << "******************";
    qDebug() << "* MD5-generator! *";
    qDebug() << "******************" << endl;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hash.db3");
    if(db.open()) {
        qDebug() << ">DB connection" << db.databaseName() << "established";
    }

    qDebug() << ">Absolute path:" << dir.absolutePath() << endl;
    qDebug() << "Give filename to generate checksum from: ";

    fileName = stream.readLine();
    QFile* file = new QFile(fileName);
        if(file->open(QIODevice::ReadOnly))
            {
                Hasher hasher(file->readAll(), QCryptographicHash::Md5);
                qDebug() << "MD5 Hash of " << fileName << " is: " << hasher.output << endl;
                file->close();
            }
    db.close();
    return a.exec();
}
