#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T13:38:46
#
#-------------------------------------------------

QT       += core gui
QT	 += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MD5-GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasedialog.cpp \
    hasher.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    databasedialog.h \
    hasher.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    databasedialog.ui \
    aboutdialog.ui
