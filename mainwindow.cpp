#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox> // For error messages
#include <QDebug>
#include "hasher.h"

QString fileFromPath; //A path to generate md5 checksum from
QString checksumFromPath; // a path to md5 checksum file to compare
QString md5ComparisonChecksum;
QFile* fileToGenerateFrom;
QFile* checksumFile;

bool md5Present = false;
bool md5ChecksumPresent = false;
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

    fileFromPath =QFileDialog::getOpenFileName(this,tr("Open File"),".","All files (*.*)");

    //Example messagebox
    //QMessageBox::information(this,tr("File Name: "),filename);
    ui->fileInputEdit->setText(fileFromPath);
}

void MainWindow::on_md5BrowseButton_clicked()
{
    checksumFromPath =QFileDialog::getOpenFileName(this,tr("Open File"),".","MD5 File (*.md5)");
    ui->md5Edit->setText(checksumFromPath);

    if(ui->md5Edit->text() != ""){
        ui->generateButton->setText("Compare");
        md5Present = true;
        md5ChecksumPresent = false;
    }
    else{
        ui->generateButton->setText("Generate");
        md5Present = false;
        //md5ChecksumPresent = true;
    }
}

void MainWindow::on_generateButton_clicked()
{
    //If there is a MD5 file selected we are doing checksum generation and comparison
    //if only a file is selected we just generate MD5 checksum and send it to DB
    fileToGenerateFrom = new QFile(fileFromPath);
    QString fileHash;
    if(fileToGenerateFrom->open(QIODevice::ReadOnly)){
        qDebug() << "Opened target file\n";
        Hasher hasher(fileToGenerateFrom->readAll(), QCryptographicHash::Md5);
        fileHash = hasher.output;
        fileToGenerateFrom->close();
    }
    if(md5ChecksumPresent) { // we don't have actual file but we do have md5 checksum
        if(fileHash == md5ComparisonChecksum) {
            //Everything's nice and dandy
            QMessageBox::information(this,tr("Success!"),tr("MD5 checksums match."));
        }
        else {
            QMessageBox::critical(this,tr("Checksum mismatch!"),tr("Checksums weren't equal!"));
        }
    }
    if(md5Present) {
        checksumFile = new QFile(checksumFromPath);
        QFileInfo fileInfo(checksumFile->fileName()); // this returns b200df688805861d6364f97d4d387775.md5
        QString comparisonMd5(fileInfo.fileName().section(".",0,0)); // let's chop off everything after .
        //QString comparisonMd5 = checksumFile->fileName().section(".",0,0);
        qDebug() << "comparisonMd5: " << comparisonMd5;
        if(fileHash == comparisonMd5) {
            //Everything's nice and dandy
            QMessageBox::information(this,tr("Success!"),tr("MD5 checksums match."));
        }
        else {
            QMessageBox::critical(this,tr("Checksum mismatch!"),tr("Checksums weren't equal!"));
        }
    }
    else {
        ui->md5Edit->setText(fileHash);
    }
}

void MainWindow::on_md5Edit_editingFinished()
{
    //User's input checking
    //If input string is a valid absolut path we are comparing target file with this file
    //if input string is not a path then it must be a Md5 checksum
    QString input;
    input = ui->md5Edit->text();
    qDebug() << "\nuser's input: "<< input;
    QFileInfo checkFile(input);
    if(checkFile.exists() && checkFile.isFile()) {
        checksumFromPath = input;
        md5Present = true;
    }
    else {
        md5ComparisonChecksum = input;
        md5ChecksumPresent = true;
        ui->generateButton->setText("Compare");
    }
}
