QT += core
QT -= gui
QT += sql

TARGET = MD5-generator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hasher.cpp

HEADERS += \
    hasher.h

