#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox> // For error messages
#include "hasher.h"

QString fileFromPath; //A path to generate md5 checksum from
QString checksumFromPath; // a path to md5 checksum file to compare
QFile* fileToGenerateFrom;
QFile* checksumFile;

bool md5Present = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileBrowseButton_clicked() {

    QString fileFromPath =QFileDialog::getOpenFileName(this,tr("Open File"),".","All files (*.*)");

    //Example messagebox
    //QMessageBox::information(this,tr("File Name: "),filename);
    ui->fileInputEdit->setText(fileFromPath);
}

void MainWindow::on_md5BrowseButton_clicked()
{
    checksumFromPath =QFileDialog::getOpenFileName(this,tr("Open File"),".","MD5 File (*.md5)");
    ui->md5Edit->setText(checksumFromPath);
    md5Present = true;
    ui->generateButton->setText("Compare");
}

void MainWindow::on_generateButton_clicked()
{
    //If there is a MD5 file selected we are doing checksum generation and comparison
    //if only a file is selected we just generate MD5 checksum and send it to DB
    fileToGenerateFrom = new QFile(fileFromPath);
    QString fileHash;
    if(fileToGenerateFrom->open(QIODevice::ReadOnly)){
        Hasher hasher(fileToGenerateFrom->readAll(), QCryptographicHash::Md5);
        fileHash = hasher.output;
        fileToGenerateFrom->close();
    }
    if(md5Present) {
        checksumFile = new QFile(checksumFromPath);
        QString comparisonMd5 = checksumFile->fileName().section(".",0,0);
    }
    else {
        ui->md5Edit->setText(fileHash);
    }
}
