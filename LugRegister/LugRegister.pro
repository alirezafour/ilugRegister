#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T15:51:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LugRegister
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    database_export.cpp

HEADERS  += mainwindow.h\
    database_export.h

FORMS    += mainwindow.ui
