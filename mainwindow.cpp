#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox> // For error messages

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

    QString filename =QFileDialog::getOpenFileName(this,tr("Open File"),".","All files (*.*)");

    //Example messagebox
    //QMessageBox::information(this,tr("File Name: "),filename);
    ui->fileInputEdit->setText(filename);
}

void MainWindow::on_md5BrowseButton_clicked()
{
    QString filename =QFileDialog::getOpenFileName(this,tr("Open File"),".","MD5 File (*.md5)");
    ui->md5Edit->setText(filename);
    md5Present = true;
}

void MainWindow::on_generateButton_clicked()
{
    //If there is a MD5 file selected we are doing checksum generation and comparison
    //if only a file is selected we just generate MD5 checksum and send it to DB
    if(md5Present) {

    }
    else {

    }
}
