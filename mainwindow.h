#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_fileBrowseButton_clicked();

    void on_md5BrowseButton_clicked();

    void on_generateButton_clicked();

    void on_md5Edit_editingFinished();

    void on_actionQuit_triggered();

    void on_actionOpen_database_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    AboutDialog *abDiag;
};

#endif // MAINWINDOW_H
